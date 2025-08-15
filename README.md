# Remote System Monitor (TCP Server)

A simple **TCP server** that monitors **system stats** (CPU usage, RAM, disk space, and network activity) and sends this information to a remote client. This project demonstrates how to use **C++** for networking, system-level programming, and client-server communication over TCP.






## 🚀 Features

- **TCP Server**: Listens for incoming connections and sends system stats.
- **System Monitoring**: Monitors CPU, RAM, disk, and network usage.
- **Client Communication**: Sends data to the client in a structured JSON format.
- **Basic Client**: A simple client that connects to the server and displays stats.
- **Expandable**: Can be extended with more features like logging, database integration, and web dashboard.





## 📂 Project Structure
```bash
/remote-system-monitor
│── src/                  
│   ├── server.cpp        # TCP server code
│   ├── system_monitor.cpp # Code for gathering system stats
│   └── client.cpp        # Simple client to request stats
│── docs/                 # README, setup guide
│── tests/                # Unit tests (optional)
│── CMakeLists.txt        # Build configuration
```



## 🛠️ Requirements

- **C++17 or higher**  
- **CMake** for build configuration
- **Linux** OS (For system monitoring functionality)
  - `/proc/meminfo` for RAM
  - `/proc/stat` for CPU stats
  - `df` for disk usage
  - `ifconfig` for network activity
 


## 🚨 Setup & Installation


### 1. Clone the repository:

```bash
git clone https://github.com/yourusername/remote-system-monitor.git
cd remote-system-monitor
```


```bash
2. Build the project:
```

mkdir build
cd build
cmake ..
make
```

3. Run the server:
```bash

./server
The server will listen for client connections on the default port (12345).
```



4. Run the client:
```bash

./client
The client will connect to the server and display the system stats.
```



Example Output
```bash

Server Output (Console):

Server is listening on port 12345...
Client connected from [192.168.1.5]
Sending system stats: {"cpu": "12.5%", "ram": "45.3%", "disk": "35%", "network": "2.4MB/s"}
Client Output (Console):

Connected to server.
Received system stats: 
{
  "cpu": "12.5%",
  "ram": "45.3%",
  "disk": "35%",
  "network": "2.4MB/s"
}
```


Features to Implement (Future Enhancements)

Logging: Log system stats to a database (SQLite/MySQL).
Web Dashboard: Real-time display of stats via a web interface.
Encryption: Add SSL/TLS encryption for secure communication.
Cross-Platform Support: Make the server work on Windows/macOS.
Multi-Client Support: Handle multiple clients simultaneously.



Author

Moafk Aljabi





📄 License

```bash
This project is licensed under the MIT License - see the LICENSE file for details.
```

