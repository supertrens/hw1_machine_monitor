#include <stdio.h>
#include <stdlib.h>
#include "client.h"

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#define PORT 9001
#define BUFFET_SIZE 1024


int main(int argc, char **argv)
{
	//create the client socket
	int network_socket = clientSocket();

	//connect to the server
	connectToServer(network_socket);

	// Route the client to the server
	// by getting the command to be send to the server
	communicateToServer(network_socket);

	return 0;
}
/******************************************************************
 *This is the most important fucntion of the program
 *This is where the client socket will be created
 * a request will be sent to the servert at port 9001
 ******************************************************************/
int clientSocket()
{
	//create a socket
	int network_socket;
	network_socket = socket(AF_INET, SOCK_STREAM, 0);

	//check if the socket has been created
	if(network_socket == -1)
		printf("The socket cannot be created!\n");
	return network_socket;
}

/*****************************************************************
 *This fucntion will recieve an integer as parameter
 * The integer value 'network_socket' will represent
 * The socket connection. All the server connection,
 * will be handled here
 ****************************************************************/
void connectToServer(const int network_socket)
{
	//specify an adress for the socket
	struct sockaddr_in server_address;
	server_address.sin_family = AF_INET;
	server_address.sin_port = htons(PORT);

	//using in.h library to get any ip adress
	server_address.sin_addr.s_addr = INADDR_ANY;

	//If connection is 0 everything is ok ,
	//If we get a value -1 , there is some error
	int connection_status = connect(network_socket,
	                                (struct sockadrr *) &server_address,sizeof(server_address));

	//check for error with the connection
	if(connection_status == -1) {
		printf("There was an error making a connection to the remote server\n\n");

		exit(EXIT_FAILURE);
	}
}

/*****************************************************************
 *This fucntion will recieve an integer as parameter
 * The integer value 'network_socket' will represent
 * The socket connection.
 *****************************************************************/

void communicateToServer(const int network_socket)
{
	//this loop will be running as long the user stay connected to the  server
	while(true) {
		char choice =' ';
		int pid =0;

		displayMenu();
		printf("which one?");
		scanf("%c", &choice);

		// I will take the use choice and call the correspondent function
		switch(choice) {
		case 'a':
			printf("%c\n",choice );
			break;
		case 'b':
		case 'c':
		case 'd':
		case 'e':
		case 'f':
		case 'g':
		case 'h':
		case 'i':
		case 'j':
			printf("pid? ");
			scanf("%d", &pid);
			break;
		case 'k':
			close(network_socket);
			break;
		default :
			printf("Out of choice \n");
		}

		//Create the request to be send to the server
		struct monitor_protocol request;
		request.choice = choice;
		request.pid = pid;

		//send the request to the server
		send(network_socket, &request, sizeof(request), 0);

		//get the server answer
		getServerResponse(network_socket);

	}
}

/******************************************************************
 * This function will prompt the menu to the user
 * The user will have choice from a to k.
 * Each of the choice will be responsible to call another function
 * That can do the task required by the user.
 *****************************************************************/
void displayMenu()
{
	char choice ;
	printf( "===============================================================================\n"
	        "\t Please select one of those options by typing the letter [a-k]\n"
	        "===============================================================================\n\n"
	      );

	printf(  "(a) list all process ids\n"

	         "(b) thread's IDs \n"
	         "(c) child's PIDs \n"
	         "(d) process name \n"
	         "(e) state of process(D,R,S,T,t,W,X,Z) \n"
	         "(f) command line of excuting process (cmdline) \n"
	         "(g) parent's PID \n"
	         "(h) all ancients of PIDs \n"
	         "(i) virtual memory size (Vmsize) \n"
	         "(j) physical memory size (VmRSS) \n"
	         "(k) exit \n\n "
	      );
}

void getServerResponse(const int network_socket)
{
	struct monitor_protocol response;

	//recieve the data from the server
	int connection_status;
	connection_status = recv(network_socket, &response, sizeof(response), 0);
	//if it is -1 an error as occured
	if(connection_status == -1)
		printf("package get corrupted");
	else if( connection_status == 0)
		printf("Something wrong happened");
	else
		printf("\n%s %s\n\n", response.description, response.info);
	// //If we can get here thats mean the connection is ok, we can preceed
	// //recieve data from the server
	// char server_response[BUFFET_SIZE];
	// recv(network_socket , &server_response , sizeof(server_response) ,0 );
	//
	// //Print out the server's response
	// printf("The server sent the data : %s\n", server_response);
	// // Close the socket
	// close(network_socket);

}
