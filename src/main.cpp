#include <LoRaWan_APP.h>                                                    // HelTec LoRa library
#include <Arduino.h>
#include <Seeed_BME280.h>
#include <CCS811.h>                                                         // HelTec modified version of Adafruit_CCS811 library (inlcuded in HelTec documentation)
#include <Wire.h>
#include "credentials.h"                                                    // OTAA keys to synchronize with TTN

#define PA2ATM 101300

bool ENABLE_DEBUG = false;                                                  // Boolean toggle to enable serial monitor
uint32_t appTxDutyCycle = 90000;                                            // Data transmission rate time (in milliseconds)

uint16_t userChannelsMask[6]={ 0x00FF,0x0000,0x0000,0x0000,0x0000,0x0000 };
LoRaMacRegion_t loraWanRegion = ACTIVE_REGION;                              // Macro that represents the region, EU868
DeviceClass_t  loraWanClass = LORAWAN_CLASS;                                // Macro that represents the device class, A
bool overTheAirActivation = LORAWAN_NETMODE;                                // Macro that represents the type of LoRa activation, OTAA
bool loraWanAdr = LORAWAN_ADR;                                              // LoRa adress
bool keepNet = LORAWAN_NET_RESERVE;
bool isTxConfirmed = LORAWAN_UPLINKMODE;                                    // TX needs to be confirmed
uint8_t appPort = 2;
uint8_t confirmedNbTrials = 4;                                              // Trials of TX

// Sensors variables -----------------------------------------------------------------------------------------
int temperature, humidity, pressure_int, pressure_dec, batteryLevel;
long pressure_pa;
float pressure_atm;
uint16_t co2_i = 0, tvoc_i = 0, co2_medio, tvoc_medio;

// Sensors constructors -------------------------------------------------------------------------------------
BME280 bme280;
CCS811 ccs;

// Function to get the average measurement of CO2 and TVOC out of 5 individual measurements -----------------
void ccs_medio(){
  co2_medio = 0;
  tvoc_medio = 0;
  for(int i = 0; i < 5; i++){
    if(!ccs.readData()){                                                    // 'ccs.readData()' is kinda tricky. It returns a true if no measurements are available, and false if it successfully found something to show. That is why it partnered with a not (!)
      co2_i = ccs.geteCO2();                                                // Both 'ccs.getCO2()' and 'ccs.getTVOC()' return the values
      co2_medio += co2_i;
      tvoc_i = ccs.getTVOC();                                               // TVOC: Total Volatile Organic Compounds
      tvoc_medio =+ tvoc_i;
      Serial.print("El CO2 en la iteracion es: ");
      Serial.println(co2_i);
      Serial.print("El TVOC en la iteracion es: ");
      Serial.println(tvoc_i);
    }
    else{
      Serial.println("ERROR!");
    }
    delay(1000);
  }
  co2_medio = co2_medio / 5;
  Serial.print("El CO2 medio es: ");
  Serial.println(co2_medio);
  tvoc_medio = tvoc_medio / 5;
  Serial.print("El TVOC medio es: ");
  Serial.println(tvoc_medio);
}

// Function to divide pressure into integer and decimal parts -----------------------------------------------
void pressure_parts(){
  float dec;
  Serial.print("La presion en Pa ");
  Serial.print(pressure_pa);
  pressure_atm = pressure_pa / PA2ATM;                                      // Pressure in atm (too many decimals)
  Serial.print("La presion en atm es: ");
  Serial.println(pressure_atm);
  pressure_int = floor(pressure_atm);                                       // Integer part of atms
  Serial.print("Parte entera de la presion en atm: ");
  Serial.println(pressure_int);
  dec = pressure_atm - pressure_int;                                        // Decimal part of atms
  dec *= 1000;                                                              // Number of decimals I want
  pressure_dec = dec;                                                       // Decimals I want as an int and without residual decimal numbers
  Serial.print("Parte decimal de la presion en atm: ");
  Serial.println(pressure_dec);
}

// Function to prepare the transmission =====================================================================
static void prepareTxFrame(uint8_t port){
  // This enables the output to power the sensor ------------------------------------------------------------
  pinMode(Vext, OUTPUT);                                                    // Vext is a reserved word to refer to the 3.3V pin of the CubeCell board
  digitalWrite(Vext, LOW);
  pinMode(GPIO0, OUTPUT);
  digitalWrite(GPIO0, LOW);
  pinMode(GPIO4, OUTPUT);                                                   // RGB LED GPIO
  digitalWrite(GPIO4, HIGH);
  delay(500);

  Serial.println("BME280 and CCS811 CubeCell test ALPHA");

  Wire.begin();
  delay(100);

  // If BME does not init, print error if serial enabled ----------------------------------------------------
  if(!bme280.init()){
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
  }

  delay(500);                                                               // This delay is required to allow the sensor time to init

  // Initialization of the variables to the BME library functions -------------------------------------------
  temperature = bme280.getTemperature() * 100;                              // As temperature is give with two decimals, it is converted to 'int'
  humidity = bme280.getHumidity();
  pressure_pa = bme280.getPressure();                                       // Pressure in Pa (long)
  pressure_parts();

  delay(100);                                                               // Delay between sensors

  // If CCS does not begin, print an error if serial enabled ------------------------------------------------
  if(!ccs.begin()){
    Serial.println("Failed to start sensor! Please check your wiring.");
    while(1);
  }

  while(!ccs.available());                                                  // Wait for the sensor to be ready

  delay(5000);                                                              // This delay is required to allow the sensor time to be available

  ccs_medio();

  Wire.end();
  
  // Turn the power to the sensor off again ----------------------------------------------------------------
  digitalWrite(Vext, HIGH);
  digitalWrite(GPIO0,HIGH);
  digitalWrite(GPIO4,LOW);

  batteryLevel = (BoardGetBatteryLevel() / 254) * 100;                      // CubeCell built-in function to get battery voltage

  // TX bytes array initialization --------------------------------------------------------------------------
  appDataSize = 13;
  appData[0] = lowByte(temperature);                                        // As temperature values range from bigger than 256 (more than a byte) and less than 65536 (less than 2 bytes), functions 'lowByte' and 'highByte' are needed
  appData[1] = highByte(temperature);

  appData[2] = lowByte(humidity);
  appData[3] = highByte(humidity);

  appData[4] = lowByte(pressure_int);
  appData[5] = lowByte(pressure_dec);
  appData[6] = highByte(pressure_dec);

  appData[7] = lowByte(batteryLevel);

  appData[8] = lowByte(co2_medio);
  appData[9] = highByte(co2_medio);

  appData[10] = lowByte(tvoc_medio);
  appData[11] = highByte(tvoc_medio);

  // Serial monitor messages to debug -----------------------------------------------------------------------
  Serial.print("Temperature: ");
  Serial.print(temperature / 100);
  Serial.print("C, Humidity: ");
  Serial.print(humidity);
  Serial.print("%, Pressure: ");
  Serial.print(pressure_atm);
  Serial.print(" atm, Battery Voltage: ");
  Serial.print(batteryLevel);
  Serial.println(" %");

  Serial.print("CO2: ");
  Serial.print(co2_medio);
  Serial.print("ppm, TVOC: ");
  Serial.println(tvoc_medio);
}

// 'setup()' function =======================================================================================
void setup(){
  // ONLY the initialization of the CubeCell board ----------------------------------------------------------
  boardInitMcu();
  if(ENABLE_DEBUG){
    Serial.begin(115200);                                                   // It is here where serial is initialized
  }

  deviceState = DEVICE_STATE_INIT;                                          // State that indicates the process of joining a LoRaWAN network
  LoRaWAN.ifskipjoin();
}

// 'loop()' function ========================================================================================
void loop(){
  // CubeCell LoRaWAN state machine -------------------------------------------------------------------------
  //Serial.println("Inicializando maquina de estados...");
  switch(deviceState){

    // State that indicates the process of joining a LoRaWAN network ----------------------------------------
    //Serial.println("Buscando red LoRaWAN");
    case DEVICE_STATE_INIT:
    {
      printDevParam();
      LoRaWAN.init(loraWanClass,loraWanRegion);
      deviceState = DEVICE_STATE_JOIN;                                      // Following state is the one that indicates the process of actively joined the network
      break;
    }

    // State that indicates the process of having joined a LoRaWAN network -----------------------------------
    //Serial.println("Uniéndome a una red LoRaWAN");
    case DEVICE_STATE_JOIN:
    {
      LoRaWAN.join();                                                       // Function to join the network
      break;
    }

    // Automatically change to send state --------------------------------------------------------------------
    //Serial.println("Preparando bytes a enviar");
    case DEVICE_STATE_SEND:
    {
      prepareTxFrame(appPort);
      LoRaWAN.send();                                                       // Function so send the bytes
      deviceState = DEVICE_STATE_CYCLE;                                     // Following state is the one to time the data transmission rate
      break;
    }

    // State that indicates the process of timing the data transmission rate --------------------------------
    //Serial.println("Temporizando duty cycle");
    case DEVICE_STATE_CYCLE:
    {
      txDutyCycleTime = appTxDutyCycle + randr(0, APP_TX_DUTYCYCLE_RND);    // Schedule next packet transmission. 'APP_TX_DUTYCYCLE_RND' defines a random delay for application data transmission duty cycle. 1s
      LoRaWAN.cycle(txDutyCycleTime);
      deviceState = DEVICE_STATE_SLEEP;                                     // Following state is to activate deep sleep
      break;
    }

    // State that indicates the process of starting deep sleep between cycles -------------------------------
    //Serial.println("Me piro a dormir!");
    case DEVICE_STATE_SLEEP:
    {
      LoRaWAN.sleep();                                                      // Function to activate deep sleep for the timed time
      break;
    }

    default:
    {
      deviceState = DEVICE_STATE_INIT;
      break;
    }
  }
}
