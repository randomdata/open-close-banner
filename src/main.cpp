/* 
  !!! IMPORTANT - Modify the secrets.h file for this project with your network connection and ThingSpeak channel details. !!!
    
  ThingSpeak ( https://www.thingspeak.com ) is an analytic IoT platform service that allows you to aggregate, visualize, and 
  analyze live data streams in the cloud. Visit https://www.thingspeak.com to sign up for a free account and create a channel.  
  
  Documentation for the ThingSpeak Communication Library for Arduino is in the README.md folder where the library was installed.
  See https://www.mathworks.com/help/thingspeak/index.html for the full ThingSpeak documentation.
  
  For licensing information, see the accompanying license file.
  
  Copyright 2018, The MathWorks, Inc.
*/
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "ThingSpeak.h"
#include "secrets.h" // header file including the tokens and passwords

WiFiClient  client;

unsigned long myChannelNumber = SECRET_CH_ID;
const char *myWriteAPIKey = SECRET_API_TOKEN;

int value = 1;

void connectToNetwork(){
  // Connect to Wifi network
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Connecting to "); Serial.print(WIFI_SSID);
    WiFi.mode(WIFI_STA);
    WiFi.begin(WIFI_SSID, WIFI_PSK);
    while(WiFi.status() != WL_CONNECTED){  
      delay(1000);
      Serial.print(".");           
    } 
    Serial.print("Connected, IP address: "); Serial.println(WiFi.localIP());
    long rssi = WiFi.RSSI();
    Serial.print("RSSI: "); Serial.println(rssi);
  }
}
// Setup
void setup() {
  Serial.begin(9600);        // Initialize serial connection
  Serial.println();
  connectToNetwork();        // Connect to Wifi
  ThingSpeak.begin(client);  // Initialize ThingSpeak
}
// Loop
void loop() {
  // Write to ThingSpeak. Here, we write to field 1.
  int x = ThingSpeak.writeField(myChannelNumber, 1, value, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  } else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  } 
  delay(3 * 60 * 1000); // Wait n minutes to update the channel again (n * 60 * 1000)
}
