// decodeUplink() JS function for TTN V3
//
// See https://www.thethingsindustries.com/docs/integrations/payload-formatters/javascript/#decode-uplink-function

function decodeUplink(input) {
  var data = {};
  var bytes = input.bytes;

  data.temperature = (bytes[0] | (bytes[1] << 8)) / 100;
  data.humidity = bytes[2] | (bytes[3] << 8);
  data.pressure = (((bytes[4])) + ((bytes[5]) << 8) + ((bytes[6]) << 16) + ((bytes[7]) << 24)) / 100;
  data.battery = (bytes[8] | (bytes[9] << 8)) / 1000;
  data.co2 = bytes[10] | (bytes[11] << 8);
  data.tvoc = bytes[14] | (bytes[13] << 8);

    return { 
      data: data,
      warnings: [],
      errors: []
  };
}
