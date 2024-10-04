# arduino-wifi-captive-portal-auth
This project connects Arduino devices to Wi-Fi networks requiring captive portal authentication. It automates login using user ID and password, allowing seamless connection in networks like campuses. Ideal for IoT applications needing continuous connectivity, such as monitoring systems and data collection.


# Arduino Wi-Fi Connection via Captive Portal Authentication

This repository provides a solution to connect Arduino devices to Wi-Fi networks that require captive portal authentication (e.g., campus networks) by passing user credentials such as a user ID and password. With this project, your Arduino can seamlessly authenticate and access the network, allowing for uninterrupted operation in environments requiring login-based access.

## Features
- **Automatic Authentication**: The code automates the process of logging into Wi-Fi networks that use captive portals.
- **Supports User ID and Password**: Designed for networks that require login credentials for access.
- **Customizable for Different Networks**: Easily adaptable for different captive portals by modifying login URLs and field parameters.
- **Stable Connection**: Ensures a stable connection for Arduino-based IoT applications like data collection, monitoring, and more.

## Requirements
- Arduino board (with Wi-Fi capability, such as ESP8266 or ESP32)
- Access to a Wi-Fi network with captive portal authentication (e.g., campus or enterprise network)
- Arduino IDE installed on your computer

## Getting Started

### 1. Clone the Repository
Clone this repository to your local machine:
```bash
git clone https://github.com/yourusername/arduino-captive-portal-authentication.git
```
### 2. Modify Wi-Fi Credentials

Before uploading the code to your device, update your Wi-Fi credentials. Locate the following lines in the code:

```cpp
char ssid[] = "SSID";   // Wi-Fi SSID
char pass[] = "passkey";   // Wi-Fi passkey
const char* username = "YourUserID";
const char* password = "YourPassword";
```
### 3. Customize the Captive Portal URL

Find the captive portal login URL for your network and update it in the code. You may also need to modify the HTTP POST request fields based on the network's login form. Look for lines similar to:

```
const char* captivePortalUrl = "http://your-captive-portal-url";
```
Make sure to replace the placeholder with your actual captive portal URL.

### 4. Upload to Arduino
Connect your Arduino to your computer and upload the sketch to the board using the Arduino IDE.

### 5. Monitor Connection
Use the Serial Monitor in the Arduino IDE to track the connection process and troubleshoot any issues.

## Troubleshooting

- **Incorrect Login Credentials:** Ensure that the user ID and password are correct.
- **Captive Portal URL:** Double-check that you are using the correct login URL for your network’s captive portal.
- **Wi-Fi Signal Strength:** Make sure the Arduino is within range of the Wi-Fi network.

## Contributing

We welcome contributions! If you have suggestions for improvements or additional features, feel free to fork this repository and submit a pull request.

## License
This project is licensed under the MIT License. See the LICENSE.txt file for more details.

Feel free to customize any sections to fit your project better!

