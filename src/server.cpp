#include "server.h"

Server::Server(int port) : m_port(port), m_serverSocket(-1) 
{}

Server::~Server()
{
    if(m_serverSocket == -1)
    {
        close(m_serverSocket);
    }
}

bool Server::initializeServer()
{

}


void Server::handleClient(int clientSocket)
{

}

void Server::handleSocket(int )
{

}

void Server::sendStats(int clientSocket)
{
    systemMonitor.getSystemStatsJSON();
}

