# ESP8266 & Raspberry Pi Socket Communication

This Snippet establishes a simple communication channel between an ESP8266 microcontroller and a Raspberry Pi using TCP sockets. The ESP8266 sends messages regarding its connection status and other data to the Raspberry Pi server.

## Feats
- **ESP8266 Setup**: Connects to a Wi-Fi network and communicates with the Raspberry Pi server over TCP.
- **Raspberry Pi Server**: Listens for incoming connections and processes messages from the ESP8266.
- **WebSocket-like Communication**: Implements lightweight TCP socket communication for IoT monitoring and control.

---

## Prerequisites

### Hardware
- **ESP8266 Microcontroller**: (e.g., NodeMCU)
- **Raspberry Pi**: Any version running a Linux-based OS

### Software
- **Python 3**: Required to run the Raspberry Pi server.
- **Websockets Library**: For WebSocket communication.

## Usage:
1) Install python3
   ```bash
   sudo apt install python3
   ```
2) Install websockets library
   ```bash
   pip install websockets
   ```
3) Clone repository
    ```bash
    git clone https://github.com/itsvenu22/octo-pancake
    ```
4) Run python file
    ```bash
    python3 octo-pancake/websocket-esp-rpi/rpi-main.py
    ```
## Configuration
- Update the ssid and password variables in the ESP8266 code with your Wi-Fi credentials.
- Replace raspberrypi.local with the actual IP address of your Raspberry Pi.
## Communication Flow
- ### ESP8266:
    - Sends a join message ("New device 1001 Joined") when it connects.
    - Periodically sends data ("777") every 3 seconds.
    - Sends an exit message ("Device 1001 exited from the network") before disconnecting.
- ### Raspberry Pi:
    - Listens on port 8081 for incoming messages.
    - Outputs relevant logs based on the received messages.
## About the websockets Library
The websockets library provides an easy way to implement WebSocket clients and servers in Python, enabling real-time, bidirectional communication between a client and a server over a single, long-lived connection.

## Key Features:
- Asynchronous Communication: Built on asyncio, allowing for non-blocking operations.
- Easy to Use: Simple API for setting up WebSocket servers and clients.
- Standards Compliant: Follows the WebSocket protocol (RFC 6455).