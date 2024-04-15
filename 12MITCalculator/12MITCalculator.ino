#include <ESP8266WiFi.h>

const char* ssid = "xxxxxxxx";
const char* password = "xxxxxxxxxx";

// Serial Monitor is started at the default Baud Rate for NodeMCU
Serial.begin(115200);

// Relay Pin is defined to NodeMCU D4 pin i.e. GPIO pin 2.
pinMode(2, OUTPUT);
digitalWrite(2, 0);

// In the void setup function, the function will try to connect to WiFi.
// This process executes in a loop, which means it runs until there is a connection to WiFi.
// So be careful before entering your WiFi SSID and Password.
void setup() {
  // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, password);
  
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println(" ");
  Serial.println("WiFi connected");
}

// In void loop, it checks if a client has connected.
// It waits until the client sends some data and performs tasks according to the input.
void loop() {
  WiFiClient client = server.available();
  
  if (!client) {
    return;
  }
  
  Serial.println("new client");
  
  while (!client.available()) {
    delay(1);
  }
  
  String req = client.readStringUntil('\r');
}
