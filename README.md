# TCP-Server-System-Monitor

A simple **TCP server** that monitors **system stats** (CPU usage, RAM, disk space, and network activity) and sends this information to a remote client.
This project uses **C++** for networking, system-level programming, and client-server communication over TCP.






##  Features

- **TCP Server**: Listens for incoming connections and sends system stats.
- **System Monitoring**: Monitors CPU, RAM, disk, and network usage.
- **Client Communication**: Sends data to the client in a structured JSON format.
- **Basic Client**: A simple client that connects to the server and displays stats.





##  Project Structure
```bash
/TCP-Server-System-Monitor
│── src/                  
│   ├── server.cpp        # TCP server code
│   ├── system_monitor.cpp # Code for gathering system stats
│   └── client.cpp        # Simple client to request stats
│── docs/                 # README, setup guide
│── tests/                # Unit tests (optional)
│── CMakeLists.txt        # Build configuration
```



##  Requirements

- **C++17 or higher**
- **rapidjson-dev**
- **CMake** for build configuration
- **Linux** OS (For system monitoring functionality)
  - `/proc/meminfo` for RAM
  - `/proc/stat` for CPU stats
  - `df` for disk usage
  - `ifconfig` for network activity
 


##  Setup & Installation

### 1. Install rapidjson-dev:
```
sudo apt update
sudo apt install rapidjson-dev
```

### 2. Clone the repository:

```bash
git clone https://github.com/moafkaljabi/TCP-Server-System-Monitor.git
cd TCP-Server-System-Monitor/server
```

### 3. Build the project:
```bash

mkdir build
cd build
cmake ..
make
```



### 4. Run the server:
```bash

./server
```
The server will listen for client connections on the default port (12345).



### 5. in a new terminal, build the client:
```bash

cd ../client
mkdir build
cd build
cmake ..
make
```

### 6. Run the client:
```bash

./client
```


The client will connect to the server and display the system stats.



Example Output
```bash

Server Output (Console):

Server is listening on port 12345...
Client connected from [ip]
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





Author: Moafk Aljabi





 License

```bash
This project is licensed under the MIT License - see the LICENSE file for details.
```







