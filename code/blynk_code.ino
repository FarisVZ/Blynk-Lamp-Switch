#define BLYNK_TEMPLATE_ID "Template-ID"
#define BLYNK_TEMPLATE_NAME "Template-Name"
#define BLYNK_AUTH_TOKEN "AUTH-Token"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


char ssid[] = "WIFI-NAME";
char pass[] = "WIFI-PASSWORD";


#define RELAY_PIN D7  


#define BLYNK_VPIN V0

void setup() {
  
  Serial.begin(115200);

  
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); 

  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}


BLYNK_WRITE(BLYNK_VPIN) {
  int value = param.asInt(); 
  digitalWrite(RELAY_PIN, !value);
}

void loop() {
  Blynk.run();
}
