// decodeUplink() JS function for TTN V3
//
// See https://www.thethingsindustries.com/docs/integrations/payload-formatters/javascript/#decode-uplink-function

function decodeUplink(input) {
  var data = {};
  var bytes = input.bytes;

  data.temperature = (bytes[0] | (bytes[1] << 8)) / 100;
  data.humidity = bytes[2];
  data.pressure = (bytes[3]) + (bytes[4] + (bytes[5] << 8)) / 1000;
  data.battery = bytes[6];
  data.co2 = bytes[7] | (bytes[8] << 8);
  data.tvoc = bytes[9] | (bytes[10] << 8);

    return {
      data: data,
      warnings: [],
      errors: []
  };
}
