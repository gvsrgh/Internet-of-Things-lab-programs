#include <ESP8266WiFi.h>

const char* ssid = "";     // Your WiFi Name
const char* password = ""; // Your WiFi password
int LED = 2;                // LED connected to GPIO2 (D4)

WiFiServer server(80);      // Create a server object listening on port 80

void setup() {
  Serial.begin(115200);     // Initialize serial communication with baud rate 115200 (Default for ESP8266)
  pinMode(LED, OUTPUT);     // Set the LED pin as an output
  digitalWrite(LED, LOW);   // Initially, turn off the LED
  
  Serial.print("Connecting to the Network");
  WiFi.begin(ssid, password);  // Connect to the WiFi network
  
  while (WiFi.status() != WL_CONNECTED) {  // Wait for WiFi connection
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("WiFi connected");
  server.begin();  // Start the server
  Serial.println("Server started");
  Serial.print("IP Address of network: ");
  Serial.println(WiFi.localIP());  // Print IP address on Serial Monitor
  Serial.print("Copy and paste the following URL: https://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}

void loop() {
  WiFiClient client = server.available();  // Check for client connections
  
  if (!client) {
    return;
  }
  
  Serial.println("Waiting for new client");
  
  while (!client.available()) {
    delay(1);
  }
  
  String request = client.readStringUntil('\r');  // Read the client's request
  
  Serial.println(request);
  client.flush();
  
  int value = LOW;
  
  if (request.indexOf("LED = ON") != -1) {
    digitalWrite(LED, HIGH);  // Turn the LED ON
    value = HIGH;
  }
  
  if (request.indexOf("LED = OFF") != -1) {
    digitalWrite(LED, LOW);  // Turn the LED OFF
    value = LOW;
  }
  
  // HTML Page Code
  client.println("HTTP/1.1 200 OK");
  client.println("Content-Type: text/html");
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.print("CONTROL LED: ");
  
  if (value == HIGH) {
    client.print("ON");
  } else {
    client.print("OFF");
  }
  
  client.println("<br><br>");
  client.println("<a href=\"/LED=ON\"><button>ON</button></a>");
  client.println("<a href=\"/LED=OFF\"><button>OFF</button></a><br/>");
  client.println("</html>");
  
  delay(1);
  Serial.println("Client disconnected");
  Serial.println();
}
