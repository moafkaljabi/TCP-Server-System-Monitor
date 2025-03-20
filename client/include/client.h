#pragma once 

#pragma once 

#include <iostream>
#include <string>

#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/stringbuffer.h>




class Client {

public:
    Client(const std::string &serverIP, int port);
    ~Client();

    void connectToServer();
    void requestStats();
    void receiveStats();
    void printStats();

private:
    std::string m_serverIP;
    int m_port;
    int m_socket;

};