# Randomdata Space open-close banner

Note:

You need a file called `include/secrets.h` with some static variables like SSID, Wifi password, Thingspeak channel_id and API write token. For an example take a look in `include/secrets_template.h`.

For the result, take a look at [the Randomdata site](https://randomdata.nl)

I've used platformIO and used the 'Thingspeak.h' library published, licensed and copywrighted by The Mathworks.
  * [Mathworks - Thingspeak](https://mathworks.com/help/thingspeak/index.html)

# References
 * https://arduino-esp8266.readthedocs.io/en/latest/esp8266wifi/readme.html
 * http://domoticx.com/esp8266-wifi-http-get-request-maken-arduinoide/
 * https://github.com/esp8266/Arduino/blob/master/libraries/ESP8266HTTPClient/src/ESP8266HTTPClient.h
 * https://www.arduino.cc/en/Reference/WiFiClient
 * http://nothans.com/measure-wi-fi-signal-levels-with-the-esp8266-and-thingspeak