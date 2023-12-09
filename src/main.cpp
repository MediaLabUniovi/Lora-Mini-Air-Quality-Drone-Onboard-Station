#include <LoRaWan_APP.h>                                                    // HelTec LoRa library
#include <Arduino.h>
#include <Seeed_BME280.h>
#include <Adafruit_CCS811.h>
#include <Wire.h>
#include "ttnvalues.h"                                                      // OTAA keys to synchronize with TTN


bool ENABLE_DEBUG = true;                                                   // Boolean toggle to enable serial monitor
uint32_t appTxDutyCycle = 30000;                                            // Data transmission rate time (in milliseconds)

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
int temperature, humidity, co2, tvoc, batteryVoltage;
long pressure;

// Sensors constructs
BME280 bme280;
Adafruit_CCS811 ccs;

// Function to prepare the transmission =====================================================================
static void prepareTxFrame(uint8_t port){
  // This enables the output to power the sensor ------------------------------------------------------------
  pinMode(Vext, OUTPUT);                                                    // Vext is a reserved word to refer to the 3.3V pin of the CubeCell board
  digitalWrite(Vext, LOW);
  delay(500);

  // If BME does not init, print error if serial enabled ----------------------------------------------------
  if(!bme280.init()){
    if(ENABLE_DEBUG){
      Serial.println("Could not find a valid BME280 sensor, check wiring!");
    }
  }

  // If CCS does not begin, print an error if serial enabled ------------------------------------------------
  if(!ccs.begin()){
    if(ENABLE_DEBUG){
      Serial.println("Failed to start sensor! Please check your wiring.");
      while(1);
    }
  }

  while(!ccs.available());                                                  // Wait for the sensor to be ready

  delay(500);                                                               // This delay is required to allow the sensor time to init
  
  // Initialization of the variables to the BME library functions -------------------------------------------
  temperature = bme280.getTemperature() * 100;                              // As temperature is give with two decimals, it is converted to 'int'
  humidity = bme280.getHumidity();
  pressure = bme280.getPressure();

  // Initialization of the variables to the CCS library functions -------------------------------------------
  co2 = ccs.geteCO2();
  tvoc = ccs.getTVOC();                                                     // TVOC: Total Volatile Organic Compounds

  Wire.end();
  
  digitalWrite(Vext, HIGH);                                                 // Turn the power to the sensor off again
  
  batteryVoltage = getBatteryVoltage();                                     // CubeCell built-in function to get battery voltage

  // TX bytes array initialization --------------------------------------------------------------------------
  appDataSize = 14;
  appData[0] = lowByte(temperature);                                        // As temperature values range from bigger than 256 (more than a byte) and less than 65536 (less than 2 bytes), functions 'lowByte' and 'highByte' are needed
  appData[1] = highByte(temperature);

  appData[2] = lowByte(humidity);
  appData[3] = highByte(humidity);

  appData[4] = (byte) ((pressure & 0X000000FF)       );                     // As pressure is a long number and could take up to 4 bytes, the following syntax is required
  appData[5] = (byte) ((pressure & 0x0000FF00) >> 8  );
  appData[6] = (byte) ((pressure & 0x00FF0000) >> 16 );
  appData[7] = (byte) ((pressure & 0xFF000000) >> 24 );

  appData[8] = lowByte(batteryVoltage);
  appData[9] = highByte(batteryVoltage);

  appData[10] = lowByte(co2);
  appData[11] = highByte(co2);

  appData[12] = lowByte(tvoc);
  appData[13] = highByte(tvoc);

  // Serial monitor messages to debug -----------------------------------------------------------------------
  if(ENABLE_DEBUG){
    Serial.print("Temperature: ");
    Serial.print(temperature / 100);
    Serial.print("C, Humidity: ");
    Serial.print(humidity);
    Serial.print("%, Pressure: ");
    Serial.print(pressure / 100);
    Serial.print(" mbar, Battery Voltage: ");
    Serial.print(batteryVoltage);
    Serial.println(" mV");

    if(ccs.available()){
      if(!ccs.readData()){
        Serial.print("CO2: ");
        Serial.print(ccs.geteCO2());
        Serial.print("ppm, TVOC: ");
        Serial.println(ccs.getTVOC());
      }
      else{
        Serial.println("ERROR!");
        while(1);
      }
    }
  }
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
  switch(deviceState){

    // State that indicates the process of joining a LoRaWAN network ----------------------------------------
    case DEVICE_STATE_INIT:
    {
      printDevParam();
      LoRaWAN.init(loraWanClass,loraWanRegion);
      deviceState = DEVICE_STATE_JOIN;                                      // Following state is the one that indicates the process of actively joined the network
      break;
    }

    // State that indicates the process of having joined a LoRaWAN network -----------------------------------
    case DEVICE_STATE_JOIN:
    {
      LoRaWAN.join();                                                       // Function to join the network
      break;
    }

    // Automatically change to send state --------------------------------------------------------------------
    case DEVICE_STATE_SEND:
    {
      prepareTxFrame(appPort);
      LoRaWAN.send();                                                       // Function so send the bytes
      deviceState = DEVICE_STATE_CYCLE;                                     // Following state is the one to time the data transmission rate
      break;
    }

    // State that indicates the process of timing the data transmission rate --------------------------------
    case DEVICE_STATE_CYCLE:
    {
      txDutyCycleTime = appTxDutyCycle + randr(0, APP_TX_DUTYCYCLE_RND);    // Schedule next packet transmission. 'APP_TX_DUTYCYCLE_RND' defines a random delay for application data transmission duty cycle. 1s
      LoRaWAN.cycle(txDutyCycleTime);
      deviceState = DEVICE_STATE_SLEEP;                                     // Following state is to activate deep sleep
      break;
    }

    // State that indicates the process of starting deep sleep between cycles -------------------------------
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
