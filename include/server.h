#pragma once 

#include "main.h"
#include "system_monitor.h"



class Server {

public:
    Server(int port);
    ~Server();

    void start();
    void stop();


    
    SystemMonitor systemMonitor;
    
    
private: 
    int m_port;
    int m_serverSocket;
    
private: 
    
    void handleClient(int clientSocket);
    void sendStats(int clientSocket);
    bool initializeServer();
    void handleSocket(int clientSocket);
    

};


