/*http://arduino.esp8266.com/stable/package_esp8266com_index.json*/

#include <ThingSpeak.h>               // add librery
#include <ESP8266WiFi.h>

WiFiClient  client;
unsigned long counterChannelNumber = 980157;                // Channel ID
const char * myCounterReadAPIKey = "CL8DHB4NZ43291ZI";      // Read API Key
const int FieldNumber1 = 1;                                 // The field you wish to read
const int FieldNumber2 = 2;                                 // The field you wish to read

void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(115200);
  Serial.println();

  WiFi.begin("POCO PHONE", "9004652173");                 // write wifi name & password           

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
  ThingSpeak.begin(client);
}

void loop() 
{
 int A = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
 Serial.println(A);
 digitalWrite(13,A);
}

