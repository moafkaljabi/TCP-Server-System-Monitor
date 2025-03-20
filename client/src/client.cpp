#include "client.h"


Client::Client(const std::string & serverIP, int port) : m_serverIP(serverIP), m_port(port), m_socket(-1)
{}


Client::~Client()
{
    if(m_socket != 0)
    {
        close(m_socket);
    }
}


void Client::connectToServer()
{
    m_socket = socket(AF_INET,SOCK_STREAM, 0);

    if(m_socket == 0)
    {
        std::cerr << "Failed to create socket\n";
        return;
    }

    sockaddr_in serverAddress{};
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(m_port);

    if(inet_pton(AF_INET, m_serverIP.c_str(), &serverAddress.sin_addr) <= 0)
    {
        std::cerr << "Invalid address\n";
        return;
    }

    if(connect(m_socket, (struct sockaddr*)& serverAddress, sizeof(serverAddress)) == -1)
    {
        std::cerr << "Failed to connect !!\n";
    }

    std::cout << "Connected successfully !\n";


}


void Client::requestStats()
{
    std::string request = "GET_STATS";
    send(m_socket, request.c_str(), request.size(), 0);

}


void Client::receiveStats()
{
    char buffer[4096];
    int bytesReceived = recv(m_socket, buffer, sizeof(buffer) -1 , 0);

    if(bytesReceived > 0)
    {
        buffer[bytesReceived] = '\0';
        std::cout << "Received stats: " << buffer << std::endl;
    }

    else
    {
        std::cerr << "Failed to receive stats !!\n";        
    }
}


void Client::printStats()
{
    requestStats();
    receiveStats();
}

