#include "client.h"

int main() {
    Client client("127.0.0.1", 8080);  // Server IP and port
    client.connectToServer();
    client.printStats();
    return 0;
}
