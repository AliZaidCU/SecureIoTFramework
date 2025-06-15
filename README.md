# Secure-IoT-Framework

A lightweight C++/Python-based communication framework designed for resource-constrained IoT devices to securely transmit data over untrusted networks using TLS 1.3, AES-256 encryption, and X.509 certificates.

## 🔒 Key Features

- **Encrypted Communication:** Secure socket layer implemented using mbedTLS/OpenSSL for IoT sensors.
- **Device Authentication:** X.509 certificate-based mutual authentication to prevent spoofing.
- **Data Integrity Checks:** SHA-256 hashing and digital signatures.
- **Threat Simulation:** Includes replay, packet sniffing, and MITM attack simulations.
- **Secure MQTT Integration:** Optional secure publish/subscribe system using TLS-secured Mosquitto broker.
- **Platform Support:** Compatible with Raspberry Pi, ESP32 (via Arduino IDE), and Linux simulation.

## 📁 File Structure

```
Secure-IoT-Framework/
├── src/
│   ├── server.c
│   ├── client.c
│   └── crypto_utils.c
├── certs/
│   ├── ca.crt
│   ├── client.crt
│   ├── client.key
│   ├── server.crt
│   └── server.key
├── test/
│   ├── replay_attack.py
│   └── sniff.py
├── README.md
└── LICENSE
```

## 💡 Tools & Tech

- **Languages:** C, C++, Python
- **Security Libraries:** OpenSSL / mbedTLS
- **Protocols:** TLS 1.3, X.509, MQTT
- **Concepts:** CIA Triad, Buffer Overflow Protection, Risk Modelling

## 🚀 Getting Started

### 1. Install Dependencies

- **OpenSSL (C):**
  - Linux: `sudo apt install libssl-dev`
  - Windows: [Download OpenSSL](https://slproweb.com/products/Win32OpenSSL.html) and add headers/libs to your compiler path.
- **Python:**
  - `pip install scapy`

### 2. Generate Certificates

Run these commands in the `certs/` directory:
```sh
# Generate CA key and certificate
openssl genrsa -out ca.key 2048
openssl req -x509 -new -nodes -key ca.key -sha256 -days 1024 -out ca.crt

# Generate server key and CSR, then sign with CA
openssl genrsa -out server.key 2048
openssl req -new -key server.key -out server.csr
openssl x509 -req -in server.csr -CA ca.crt -CAkey ca.key -CAcreateserial -out server.crt -days 500 -sha256

# Generate client key and CSR, then sign with CA
openssl genrsa -out client.key 2048
openssl req -new -key client.key -out client.csr
openssl x509 -req -in client.csr -CA ca.crt -CAkey ca.key -CAcreateserial -out client.crt -days 500 -sha256
```

### 3. Build the C Code

- On Linux:
  ```sh
  gcc src/server.c -o server -lssl -lcrypto
  gcc src/client.c -o client -lssl -lcrypto
  ```
- On Windows: Use your C compiler and link with OpenSSL libraries.

### 4. Run the Server

```
./server
```

### 5. Run the Client

```
./client
```

### 6. Test Python Scripts

- **Replay Attack:**
  ```sh
  python test/replay_attack.py
  ```
- **Packet Sniffing:** (run as admin/root)
  ```sh
  python test/sniff.py
  ```

## 🛡️ Security

- **TLS 1.3** for encrypted transport.
- **AES-256** for symmetric encryption.
- **X.509 certificates** for mutual authentication.
- **SHA-256** for data integrity.
- **Digital signatures** for authenticity.

## 🧪 Threat Simulation

- **Replay Attack:** `test/replay_attack.py`
- **Packet Sniffing:** `test/sniff.py`
- **MITM Attack:** (to be implemented)

## 🤝 Contributing

Pull requests are welcome! For major changes, please open an issue first to discuss what you would like to change.

## 🛠️ Troubleshooting
- Ensure OpenSSL is installed and available to your compiler.
- Run Python sniffing as administrator/root.
- Use valid certificates signed by your CA.
- For Windows, ensure all DLLs for OpenSSL are in your PATH.
