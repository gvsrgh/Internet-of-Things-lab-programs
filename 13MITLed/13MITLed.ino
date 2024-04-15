#include <ESP8266WiFi.h>

const char* ssid = "Enter Your Wifi Name";
const char* password = "Enter Your WiFi password";
WiFiServer server(80);

void setup() {
  Serial.begin(115200); // Default Baud Rate for NodeMCU
  delay(10);
  pinMode(2, OUTPUT); // Connect Relay to NodeMCU’s D4 pin
  digitalWrite(2, 0);
  
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
  
  Serial.println("");
  Serial.println("WiFi connected");
  
  // Start the server
  server.begin();
  Serial.println("Server started");
  
  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();
  
  if (!client) {
    return;
  }
  
  // Wait until the client sends some data
  Serial.println("new client");
  
  while (!client.available()) {
    delay(1);
  }
  
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();
  
  int val;
  
  if (req.indexOf("/gpio/0") != -1) {
    val = 0;
  }
  else if (req.indexOf("/gpio/1") != -1) {
    val = 1;
  }
  else {
    Serial.println("invalid request");
    client.stop();
    return;
  }
  
  // Set GPIO2 according to the request
  digitalWrite(2, val);
  client.flush();
  
  String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\nGPIO is now ";
  s += (val) ? "high" : "low";
  s += "</html>";
}
