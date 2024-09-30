#include <ESP8266WiFi.h>

const char* ssid = "your_ssid";
const char* password = "your_secret_password";

const char* serverIP = "raspberrypi.local";
const int serverPort = 8081;

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  WiFiClient client;
  if (client.connect(serverIP, serverPort)) {
    client.print("New device 1001 Joined");
    client.stop();
  }
}

void disconnectESP8266() {
  WiFiClient client;
  if (client.connect(serverIP, serverPort)) {
    client.print("Device 1001 exited from the network");
    client.stop();
  }
  WiFi.disconnect();
  Serial.println("ESP8266 turned off");
}

void loop() {
  WiFiClient client;
  if (client.connect(serverIP, serverPort)) {
    client.print("777");
    client.stop();
  }
  delay(3000);
  
  delay(6000);
  disconnectESP8266();
}
