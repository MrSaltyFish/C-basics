// TCP CLIENT
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080

int main() {
	int sock = 0;
	struct sockaddr_in serv_addr;
	char *message = "Hello, Server!";
	char buffer[1024] = {0};

	// Creating socket
	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		printf("Socket creation error\n");
		return -1;
	}

	// Setting up the server address structure
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(PORT);

	// Converting IPv4/IPv6 address from text to binary form
	if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
		printf("Invalid address/ Address not supported\n");
		return -1;
	}

	// Connecting to the server
	if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
		printf("Connection failed\n");
		return -1;
	}

	// Sending message to the server
	send(sock, message, strlen(message), 0);
	printf("Message sent: %s\n", message);

	// Reading acknowledgment from the server
	read(sock, buffer, 1024);
	printf("Acknowledgment from server: %s\n", buffer);

	// Closing the socket
	close(sock);

	return 0;
}