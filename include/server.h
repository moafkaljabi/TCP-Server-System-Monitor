#pragma once 

#include "main.h"





class Server {

public:
    Server(int port);
    ~Server();

    void start();
    void stop();


private:
     void handleClient(int clientSocket);
     void sendStats(int clientSocket);


private: 
    int port;
    int serverSocket;
    bool running;
};