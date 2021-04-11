#include<CayenneMQTTESP8266.h>
#define CAYENNE_PRINT Serial
char ssid[] = "your ssid";
char password[] = "wifi password";
int pir = D12; // connect pir in D12
int value = 0;
char username[] = "mqtt user";
char mqtt_pass[] = "mqtt password";
char client_id[] = "id";

void setup() {
  Cayenne.begin(username, mqtt_pass, client_id, ssid, password);
  pinMode(pir, INPUT);
}

void loop() {
  Cayenne.loop();
  value = digitalRead(pir);
  if (value == HIGH) {
    Cayenne.virtualWrite(1, HIGH, TYPE_DIGITAL_SENSOR, UNIT_DIGITAL);
    delay(1000);
  }
  else {
    Cayenne.virtualWrite(1, LOW, TYPE_DIGITAL_SENSOR, UNIT_DIGITAL);
    delay(1000);
  }





}
