// UDP CLient
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define BUFSIZE 1024

int main() {
	int sockfd;
	struct sockaddr_in server_addr;
	char *message = "Hello, Server!";
	char buffer[BUFSIZE];
	socklen_t addr_len = sizeof(server_addr);

	// Creating socket
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}

	// Setting up the server address
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(PORT);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	// Sending message to the server
	sendto(sockfd, message, strlen(message), 0,
		   (const struct sockaddr *)&server_addr, addr_len);
	printf("Message sent: %s\n", message);

	// Receiving acknowledgment from the server
	int n = recvfrom(sockfd, buffer, BUFSIZE, 0,
					 (struct sockaddr *)&server_addr, &addr_len);
	buffer[n] = '\0';  // Null-terminate the received string
	printf("Acknowledgment from server: %s\n", buffer);

	// Closing the socket
	close(sockfd);

	return 0;
}