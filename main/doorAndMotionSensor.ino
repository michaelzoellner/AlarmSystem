#include <ArduinoJson.h>
#include <TimeLib.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WiFiMulti.h> 
#include <ESP8266mDNS.h>
#include <ESP8266WebServer.h> 

const int m_trigPin = 12;
const int m_echoPin = 13;
const int m_pirPin = 5;

int bootTime;
bool motionDetected = false;
int lastMotionDetected = 0;
bool doorOpen = false;
int lastDoorClosing;

ESP8266WiFiMulti wifiMulti;     // Create an instance of the ESP8266WiFiMulti class, called 'wifiMulti'

ESP8266WebServer server(80);    // Create a webserver object that listens for HTTP request on port 80


void setup() {
  bootTime = now();
  lastDoorClosing = now();
  
  Serial.begin(115200);         // Start the Serial communication to send messages to the computer
  delay(10);
  Serial.println('\n');

  wifiMulti.addAP("ssid_from_AP_1", "your_password_for_AP_1");   // add Wi-Fi networks you want to connect to
  
  Serial.println("Connecting ...");
  int i = 0;
  while (wifiMulti.run() != WL_CONNECTED) { // Wait for the Wi-Fi to connect: scan for Wi-Fi networks, and connect to the strongest of the networks above
    delay(250);
    Serial.print('.');
  }
  Serial.println('\n');
  Serial.print("Connected to ");
  Serial.println(WiFi.SSID());              // Tell us what network we're connected to
  Serial.print("IP address:\t");
  Serial.println(WiFi.localIP());           // Send the IP address of the ESP8266 to the computer

  if (MDNS.begin("esp8266")) {              // Start the mDNS responder for esp8266.local
    Serial.println("mDNS responder started");
  } else {
    Serial.println("Error setting up MDNS responder!");
  }

  server.on("/", handleRoot);               // Call the 'handleRoot' function when a client requests URI "/"
}

void loop() {
  doorOpen = checkDoor();
  motionDetected = checkMotion();
  server.handleClient(); 
}

bool checkDoor() {
  return false;
}

bool checkMotion() {
  if (now() - bootTime > pirWarmUpDuration) {
    long state = digitalRead(pirPin);
    if (state == HIGH) {
      Serial.println("Motion detected!")
      lastMotionDetected = now();
      return true;
    } else {
      Serial.println("No motion detected.")
      return false;
    }
  } else {
    Serial.println("PIR sensor still warming up...")
    return false;
  }
}

void handleRoot() {
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.createObject();
  root["motionDetected"] = motionDetected;
  root["lastMotionDetected"] = lastMotionDetected;
  root["doorOpen"] = doorOpen;
  root["lastDoorOpen"] = lastDoorOpen;
  String webdocument = "";
  root.printTo(webdocument);
  server.send(200, "application/json", webdocument);
}
