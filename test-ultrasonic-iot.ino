#include "Leanbot.h"          
#include "LeanbotIoT.h"       
 
#define  WIFI_SSID      F( "LAPTOP" )      
#define  WIFI_PASSWORD  F( "1234567890" ) 
 
#define  IOT_ASSET_ID   F( "2PM2kk6AwnSx2Lzx48M2V7" ) 
#define  IOT_REALM      F( "pythaverse" )

auto IoT_Distance = LbIoT.Asset.attribute(F( "ultrasonic" )); 

void setup()
{
  Leanbot.begin();
  
  bool wifiConnected = LbIoT.Wifi.begin( WIFI_SSID, WIFI_PASSWORD );     
  bool assetConnected = LbIoT.Asset.begin( IOT_ASSET_ID, IOT_REALM );   
  Serial.println(String(wifiConnected) + String(assetConnected));

  if (wifiConnected || assetConnected) {
    LbRGB.fillColor(0xff0000, BITMAP(ledO, ledA, ledB, ledC, ledD, ledE, ledF));
    LbRGB.show();
    while(true) {}
  }
}

void loop()
{
  int distance = Leanbot.pingCm();
  Serial.println(distance);
  IoT_Distance.write(String(distance));
  delay(1000);
}
