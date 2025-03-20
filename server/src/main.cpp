#include "main.h"
#include "server.h"

#include <signal.h>
#include <iostream>
#include <cstdlib>  // For exit()

volatile sig_atomic_t keepRunning = 1;

void signalHandler(int sig) {
    std::cout << "Signal " << sig << " received." << std::endl;
    // You can also perform other cleanup tasks or shutdown operations
    exit(0); // Clean shutdown
}

int main() {
    signal(SIGINT, signalHandler);  // Catch SIGINT (Ctrl+C)
    
    Server server(8080);
    server.start();
    
    return 0;
}
