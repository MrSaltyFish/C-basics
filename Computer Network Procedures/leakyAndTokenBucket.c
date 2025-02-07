#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUCKET_SIZE 10	// Max capacity of the bucket
#define PACKET_RATE 4	// Incoming tokens/packets per second

struct packet {
	int time;
	int size;
} p[50];

// Function prototypes
void leakyBucket();
void tokenBucket();
void addTokens(int *bucket, int tokens);
void processPacket(int *bucket, int packet_size);

int main() {
	int choice;
	do {
		printf("\n1. Leaky Bucket Algorithm");
		printf("\n2. Token Bucket Algorithm");
		printf("\n3. Exit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch (choice) {
			case 1:
				leakyBucket();
				break;
			case 2:
				tokenBucket();
				break;
			case 3:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice. Try again.\n");
		}
	} while (choice != 3);

	return 0;
}

// Leaky Bucket Implementation
void leakyBucket() {
	int n, bsize, bfilled = 0, outrate, m, k = 0;

	printf("\nEnter the number of packets: ");
	scanf("%d", &n);

	printf("Enter packets in the order of their arrival time:\n");
	for (int i = 0; i < n; i++) {
		printf("Enter time and size of packet %d: ", i + 1);
		scanf("%d%d", &p[i].time, &p[i].size);
	}

	printf("Enter the bucket size: ");
	scanf("%d", &bsize);

	printf("Enter the output rate: ");
	scanf("%d", &outrate);

	m = p[n - 1].time;	// Last packet's arrival time
	int i = 1;

	while (i <= m || bfilled != 0) {
		printf("\n\nAt time %d:", i);

		// Add packet to bucket if it arrives
		if (k < n && p[k].time == i) {
			if (bsize >= bfilled + p[k].size) {
				bfilled += p[k].size;
				printf("\n%d byte packet is inserted", p[k].size);
			} else {
				printf("\n%d byte packet is discarded", p[k].size);
			}
			k++;
		}

		// Process packets in the bucket
		if (bfilled == 0) {
			printf("\nNo packets to transmit");
		} else if (bfilled >= outrate) {
			bfilled -= outrate;
			printf("\n%d bytes transferred", outrate);
		} else {
			printf("\n%d bytes transferred", bfilled);
			bfilled = 0;
		}

		printf("\nPackets in the bucket: %d bytes", bfilled);
		i++;
	}
}

// Token Bucket Implementation
void tokenBucket() {
	int incomingPackets[] = {2, 3, 5, 7, 1, 4};	 // Sample packet sizes
	int n = sizeof(incomingPackets) / sizeof(incomingPackets[0]);
	int bucket = 0;	 // Current number of tokens in the bucket

	for (int i = 0; i < n; i++) {
		printf("\nTime %d seconds: \n", i + 1);
		addTokens(&bucket, PACKET_RATE);
		printf("Added %d tokens. Bucket now contains %d tokens.\n", PACKET_RATE,
			   bucket);
		processPacket(&bucket, incomingPackets[i]);
		sleep(1);  // Simulate 1-second time delay
	}
}

// Add tokens to the bucket for Token Bucket Algorithm
void addTokens(int *bucket, int tokens) {
	*bucket += tokens;
	if (*bucket > BUCKET_SIZE) {
		*bucket = BUCKET_SIZE;	// Overflow control
	}
}

// Process a packet for Token Bucket Algorithm
void processPacket(int *bucket, int packet_size) {
	if (packet_size <= *bucket) {
		*bucket -= packet_size;
		printf("Processed packet of size %d. Tokens left: %d\n", packet_size,
			   *bucket);
	} else {
		printf("Not enough tokens to process packet of size %d. ", packet_size);
		printf("Tokens left: %d\n", *bucket);
	}
}
