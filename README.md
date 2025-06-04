# ESP32_Bluetooth
# ESP32 Bluetooth Communication: Server-Client via SPP

This project demonstrates a Bluetooth Classic (SPP) communication system between two ESP32 boards, where one acts as a **server** and the other as a **client**.

## Features

- Bluetooth SPP communication
- Manual pairing using a fixed PIN (`1234`)
- Periodic message transmission from client to server
- Server responds with an acknowledgment
- Serial output for debugging and monitoring

## Hardware Requirements

- 2x ESP32 development boards
- USB cables
- Computer with Arduino IDE 2.x

## Software Requirements

- Arduino IDE 2.x
- ESP32 board support installed (via Boards Manager)
- `BluetoothSerial.h` library (included in ESP32 core)

## Setup Instructions

### 1. Flash the Server Code

Upload the `ESP32_bluetooth_server.ino` sketch to the ESP32 that will act as the server.

- The server starts a Bluetooth service named `MiServidor`.
- It requires manual pairing with PIN `1234`.

### 2. Flash the Client Code

Upload the `ESP32_bluetooth_client.ino` sketch to the second ESP32 acting as the client.

- The client attempts to connect to the server using its MAC address.
- Update the MAC address in the client code with your server’s actual address.

### 3. Pairing

If needed, manually pair the ESP32 server from your PC or smartphone using PIN `1234`. This step may help bypass connection failures due to missing trust relationships between devices.

### 4. Monitoring

Open two Serial Monitors (one for each board) at **115200 baud** to view message transmission and connection status.

## Limitations

- ESP32 in client mode has limited support for authenticated pairing.
- You may need to manually pair the devices outside of code depending on your OS and hardware behavior.
- Connection is not encrypted or authenticated beyond the PIN pairing.

## Example Output

**Server Serial Monitor:**
