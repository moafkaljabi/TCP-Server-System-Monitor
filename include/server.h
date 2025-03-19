#pragma once 

#include "main.h"
#include "system_monitor.h"



class Server {

public:
    Server(int port);
    ~Server();

    void start();
    void stop();


private:
     void handleClient(int clientSocket);
     void sendStats(int clientSocket);
     
     SystemMonitor systemMonitor;


private: 
    int m_port;
    int m_serverSocket;

private: 
    bool initializeServer();
    void handleSocket(int clientSocket);
    

};