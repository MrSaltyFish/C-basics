// UDP Server
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define PORT 8080
#define BUFSIZE 1024

int main() {
	int sockfd;
	struct sockaddr_in server_addr, client_addr;
	char buffer[BUFSIZE];
	char *ack = "Message received";
	socklen_t addr_len = sizeof(client_addr);

	// Creating socket file descriptor
	if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
		perror("Socket creation failed");
		exit(EXIT_FAILURE);
	}

	// Setting up the server address
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = INADDR_ANY;
	server_addr.sin_port = htons(PORT);

	// Binding the socket to the specified port
	if (bind(sockfd, (const struct sockaddr *)&server_addr,
			 sizeof(server_addr)) < 0) {
		perror("Bind failed");
		close(sockfd);
		exit(EXIT_FAILURE);
	}

	printf("UDP Server is listening on port %d...\n", PORT);

	// Receiving data from the client
	int n = recvfrom(sockfd, buffer, BUFSIZE, 0,
					 (struct sockaddr *)&client_addr, &addr_len);
	buffer[n] = '\0';  // Null-terminate the received string
	printf("Message received: %s\n", buffer);

	// Sending acknowledgment to the client
	sendto(sockfd, ack, strlen(ack), 0, (const struct sockaddr *)&client_addr,
		   addr_len);
	printf("Acknowledgment sent to client.\n");

	// Closing the socket
	close(sockfd);

	return 0;
}