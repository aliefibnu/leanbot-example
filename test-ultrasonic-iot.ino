#include "Leanbot.h"          // Leanbot library
#include "LeanbotIoT.h"       // Leanbot IoT library
 
// Wifi & IoT Dashboard setup
#define  WIFI_SSID      F( "Pribadi" )      //change the wifi user ID
#define  WIFI_PASSWORD  F( "TANYASAMAAKU" ) //change the wifi password
 
#define  IOT_ASSET_ID   F( "2PM2kk6AwnSx2Lzx48M2V7" ) //change the Dashboard link
#define  IOT_REALM      F( "pythaverse" )

auto IoT_Distance = LbIoT.Asset.attribute(F( "ultrasonic" )); //change the Attribute name (follow dashboard)

void setup()
{
  Leanbot.begin();
  LbIoT.Wifi.begin( WIFI_SSID, WIFI_PASSWORD );     // Connect to Wi-Fi
  LbIoT.Asset.begin( IOT_ASSET_ID, IOT_REALM );     // Connect to IoT dashboard
}

void loop()
{
  int distance = Leanbot.pingCm();
  IoT_Distance.write(String(distance));
  delay(1000);
}
