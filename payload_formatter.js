// decodeUplink() JS function for TTN V3
//
// See https://www.thethingsindustries.com/docs/integrations/payload-formatters/javascript/#decode-uplink-function

function decodeUplink(input) {
  var data = {};
  var bytes = input.bytes;

  data.temperature = (bytes[0] | (bytes[1] << 8)) / 100;
  data.humidity = bytes[2] | (bytes[3] << 8);
  data.pressure = (bytes[4]) + (bytes[5] + (bytes[6] << 8)) / 1000;
  data.battery = (bytes[7] | (bytes[8] << 8)) / 1000;
  data.co2 = bytes[9] | (bytes[10] << 8);
  data.tvoc = bytes[11] | (bytes[12] << 8);

    return {
      data: data,
      warnings: [],
      errors: []
  };
}
