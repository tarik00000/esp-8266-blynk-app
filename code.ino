#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME ""
#define BLYNK_AUTH_TOKEN ""

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
// Your Wi-Fi credentials
char ssid[] = "Your-Wifi-name";
char password[] = "Your-password-wifi";

// Pin where the external LED is connected (use GPIO 5 = D1)
#define LED_PIN 5

void setup() {
  // Start Serial Monitor
  Serial.begin(115200);
  
  // Initialize the LED pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // Turn LED off initially

  // Connect to Blynk
  Blynk.begin(auth, ssid, password);
}

// Blynk function to control the external LED
BLYNK_WRITE(V0) {
  int ledState = param.asInt(); // Get the value from the button
  digitalWrite(LED_PIN, ledState); // Turn LED ON or OFF
}

void loop() {
  // Run Blynk
  Blynk.run();
}
