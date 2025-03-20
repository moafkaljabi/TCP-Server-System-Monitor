#include "server.h"

Server::Server(int port) : m_port(port), m_serverSocket(-1) 
{}

Server::~Server()
{
    if(m_serverSocket != -1)
    {
        close(m_serverSocket);
    }
}

bool Server::initializeServer()
{
    m_serverSocket = socket (AF_INET, SOCK_STREAM, 0);   
    
    
    // if(), fails...
    if(m_serverSocket < 0)
    {
        std::cerr << "Server initialization failed !\n"; 
        return false;
    }


    // Define the socket
    sockaddr_in serverAddress;
    
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(m_port);


    //if(bind), pass: the sock_fd, struct pointer to server address, size of server address.
     if(bind(m_serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0)
    {
        std::cerr << "Failed to bind !!\n";
        return false;
    }


    // if(listen)
    if(listen(m_serverSocket,5) < 0)
    {
        std::cerr << "Failed to listen !!\n";
        return false;
    }


    std::cout << "Server is listening ..." << std::endl;
    return true;


}


void Server::handleClient(int clientSocket)
{
    std::thread clientThread([this, clientSocket](){
        std::string response = systemMonitor.getSystemStatsJSON();
        send(clientSocket, response.c_str(), response.size(), 0);
        std::cout << "Sent data successfully\n";

//        close(clientSocket);
    });
    clientThread.detach();
}





void Server::start()
{
    if(!initializeServer()){}

    while(true)
    {
        sockaddr_in clientAddr;
        socklen_t clientAddrLen = sizeof(clientAddr);
        int clientSocket = accept(m_serverSocket, (struct sockaddr*)&clientAddr, &clientAddrLen);


        
        if(clientSocket < 0)
        {
            std::cerr << "Failed to accept connection\n";
            //continue;
        }


        handleClient(clientSocket);
    }
}



