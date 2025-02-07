// TCP SERVER
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <winsock2.h>

#define PORT 8080

int main() {
	int server_fd, new_socket;
	struct sockaddr_in address;
	int addrlen = sizeof(address);
	char buffer[1024] = {0};
	char *ack = "Message received";

	// Creating socket file descriptor
	if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
		perror("Socket failed");
		exit(EXIT_FAILURE);
	}

	// Setting up the address structure
	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY;
	address.sin_port = htons(PORT);

	// Binding the socket to the specified port
	if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
		perror("Bind failed");
		exit(EXIT_FAILURE);
	}

	// Listening for incoming connections
	if (listen(server_fd, 3) < 0) {
		perror("Listen failed");
		exit(EXIT_FAILURE);
	}

	printf("Server is listening on port %d...\n", PORT);

	// Accepting an incoming connection
	if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
							 (socklen_t *)&addrlen)) < 0) {
		perror("Accept failed");
		exit(EXIT_FAILURE);
	}

	// Reading message from the client
	read(new_socket, buffer, 1024);
	printf("Message received: %s\n", buffer);

	// Sending acknowledgment back to the client
	send(new_socket, ack, strlen(ack), 0);
	printf("Acknowledgment sent to client.\n");

	// Closing the socket
	close(new_socket);
	close(server_fd);

	return 0;
}