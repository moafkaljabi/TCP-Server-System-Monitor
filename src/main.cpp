#include "main.h"
#include "server.h"
const int port = 8888;

int main () 
{
    // Create socket 

    Server server(8080);
    server.start();
}


