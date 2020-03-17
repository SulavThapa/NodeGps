#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <TinyGPS++.h>

// Set these to run example.
#define FIREBASE_HOST "sulav-21.firebaseio.com"
#define FIREBASE_AUTH "nvSu78oDsPJOgS1LGwkfKsLMAiinjgn1A6aMgQpK"
#define WIFI_SSID "Sulav21Silva"
#define WIFI_PASSWORD "sulavthapa"
TinyGPSPlus gps;

float latitude = gps.location.lat();
float longitude = gps.location.lng();

String lat_str , lng_str;

void setup() {
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  Serial.println(latitude);
  lat_str = String(latitude , 6); // latitude location is stored in a string
  Serial.println(longitude);
  lng_str = String(longitude , 6); //longitude location is stored in a string
  Firebase.setString("longi", lat_str);
  Firebase.setString("lati", lng_str);
  delay(1000);
}
