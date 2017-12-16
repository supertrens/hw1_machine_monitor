#include "server.h"
#include <stdlib.h>
#include <stdio.h>

#include<sys/socket.h>
#include<sys/types.h>

#include<netinet/in.h>

#define PORT 9001
#define BUFFET_SIZE 1024

void serverSocket()
{

	char server_message[BUFFET_SIZE] = " You have reached the server! ";

	int server_socket;
	server_socket = socket (AF_INET, SOCK_STREAM, 0);

	//define the server address
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);
	server_address.sin_addr.s_addr = INADDR_ANY;

	//bind the socket to our specified IP and port
	bind(server_socket, (struct sockadrr*) &server_address,
	     sizeof(server_address));

	//Listen to the connection #% mean we can listen to 5 at once , ic an change it later
	listen(server_socket, 5);

	int client_socket;
	client_socket = accept(server_socket, NULL, NULL);

	//send the message
	send(client_socket, server_message,sizeof(server_message), 0);
	while(1) {
		// Clean The Message buffer
		memset(BUFFET_SIZE, '0', sizeof(BUFFET_SIZE));
		// First , connection accept  => deliver the message first)
		strcpy(BUFFET_SIZE, "\nWelcome to F74027036 'HW1' server!\n");

		memset(BUFFET_SIZE, '\0', sizeof(BUFFET_SIZE));

	}

	//close the socket
	close(server_socket);
}


int main(int argc, char **argv)
{
	serverSocket();
	return 0 ;
}
