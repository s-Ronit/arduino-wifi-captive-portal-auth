#include <WiFiNINA.h>
#include <WiFiClient.h>
#include <ArduinoHttpClient.h>

char ssid[] = "NITK-NET";   // Wi-Fi SSID
char pass[] = "2K16NITK";   // Wi-Fi passkey
int status = WL_IDLE_STATUS;

// Captive portal details
char server[] = "10.10.54.4";  // Captive portal IP address
int port = 8090;               // Captive portal port
String loginPage = "/httpclient.html";  // Login endpoint
String userId = "2320410";              // User ID
String userPass = "Iamatnitk@345";      // User password

WiFiClient wifiClient;
HttpClient httpClient = HttpClient(wifiClient, server, port);

void setup() {
  Serial.begin(9600);
  while (!Serial);

  // Print MAC address for debugging
  printMacAddress();

  // Attempt to connect to Wi-Fi network
  connectToWiFi();

  // If connected, attempt to log in to the captive portal
  loginToCaptivePortal();
}

void loop() {
  // Add any code that needs to run after the connection and login process
}

void connectToWiFi() {
  while (status != WL_CONNECTED) {
    Serial.print("Attempting to connect to network: ");
    Serial.println(ssid);
    
    // Begin WiFi connection
    status = WiFi.begin(ssid, pass);

    if (status == WL_CONNECTED) {
      Serial.println("Connected to Wi-Fi!");
      
      // Wait a bit to stabilize connection
      delay(2000);  
    } else {
      Serial.print("Connection failed with status: ");
      Serial.println(status); // This will print the status code
      delay(5000);  // Retry after 5 seconds
    }
  }
}

void loginToCaptivePortal() {
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Sending login request to captive portal...");

    // Form the POST data
    String postData = "mode=191&username=" + userId + "&password=" + userPass + "&a=" + String(millis());

    // Send the HTTP POST request
    httpClient.beginRequest();
    httpClient.post(loginPage);
    httpClient.sendHeader("Content-Type", "application/x-www-form-urlencoded");
    httpClient.sendHeader("Content-Length", postData.length());
    httpClient.beginBody();
    httpClient.print(postData);  // Send the form data
    httpClient.endRequest();

    // Wait for the response
    int statusCode = httpClient.responseStatusCode();
    String response = httpClient.responseBody();

    // Print the response for debugging
    Serial.print("Status Code: ");
    Serial.println(statusCode);
    Serial.print("Response: ");
    Serial.println(response);

    if (statusCode == 200) {
      Serial.println("Successfully logged in to the captive portal!");
    } else {
      Serial.println("Failed to log in to the captive portal.");
    }
  } else {
    Serial.println("Not connected to Wi-Fi. Cannot send login request.");
  }
}

void printMacAddress() {
  // Print your board's MAC address:
  byte mac[6];
  WiFi.macAddress(mac);
  Serial.print("MAC Address: ");
  for (int i = 5; i >= 0; i--) {
    if (mac[i] < 16) {
      Serial.print("0");
    }
    Serial.print(mac[i], HEX);
    if (i > 0) {
      Serial.print(":");
    }
  }
  Serial.println();
}
