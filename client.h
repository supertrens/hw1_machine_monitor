#ifndef CLIENT_H
#define CLIENT_H

#include "protocol.h"

//My Functions prototype her
int clientSocket();
void connectToServer(const int network_socket);
void communicateToServer(const int network_socket);
void displayMenu();
void getServerResponse(const int network_socket);

#endif
