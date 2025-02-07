#include <stdio.h>
#define BUCKET_SIZE 100
#define PACKET_SIZE 50

struct packet {
	int size;
	int time;
} packets[50];

void leakyBucket() {
	int numberOfPackets, bucketFilled = 0, packetIndex = 0, seconds = 0,
						 lastArrival, bucketSize = 0, outputRate = 5;
	printf("\nEnter the number of packets: ");
	scanf("%d", &numberOfPackets);
	for (int i = 0; i < numberOfPackets; i++) {
		printf("Packet #%d: \n\tTime: ", i + 1);
		scanf("%d", &packets[i].time);
		printf("\tSize: ");
		scanf("%d", &packets[i].size);
	}

	printf("\nEnter the bucket size: ");
	scanf("%d", &bucketSize);

	printf("\nEnter the output rate: ");
	scanf("%d", &outputRate);

	lastArrival = packets[numberOfPackets - 1].time;

	while (seconds <= lastArrival || bucketFilled != 0) {
		if (packets[packetIndex].time == seconds) {
			if (bucketSize >= packets[packetIndex].size + bucketFilled) {
				bucketFilled += packets[packetIndex].size;
				printf("\nPacket of size %d accepted at time %d.",
					   packets[packetIndex].size, seconds);
			} else {
				printf("\nPacket of size %d rejected at time %d.",
					   packets[packetIndex].size, seconds);
			}
			packetIndex++;
		}

		if (bucketFilled == 0) {
			printf("\nNo packets to transmit at time: %d", seconds);
		} else if (bucketFilled <= outputRate) {
			printf("\n%d bytes transmitted at time: %d", bucketFilled, seconds);
			bucketFilled = 0;
		} else {
			bucketFilled -= outputRate;
			printf("\n%d bytes transmitted at time: %d", outputRate,
				   seconds + 1);
		}

		printf("\nPackets in the bucket: %d bytes\n", bucketFilled);

		seconds++;
	}
}

void tokenBucket() {
	int currentTokens = 0, tokenRate, maxTokens, lastArrival, numberOfPackets,
		packetIndex = 0, seconds = 0;

	printf("\nEnter the number of packets: ");
	scanf("%d", &numberOfPackets);
	for (int i = 0; i < numberOfPackets; i++) {
		printf("Packet #%d: \n\tTime: ", i + 1);
		scanf("%d", &packets[i].time);
		printf("\tSize: ");
		scanf("%d", &packets[i].size);
	}

	printf("\nEnter the maximum number of tokens: ");
	scanf("%d", &maxTokens);
	printf("\nEnter the rate of generating tokens: ");
	scanf("%d", &tokenRate);

	lastArrival = packets[numberOfPackets - 1].time;

	while (seconds < lastArrival) {
		currentTokens = maxTokens > (currentTokens + tokenRate)
							? (currentTokens + tokenRate)
							: maxTokens;

		if (packets[packetIndex].time == seconds) {
			if (packets[packetIndex].size > currentTokens) {
				printf("Not enough tokens, packet disregarded.");
			} else {
				printf("Packet of size %d accepted.",
					   packets[packetIndex].size);
			}
			packetIndex++;
		}

		if (packets[packetIndex].size > currentTokens) {
			printf("Packet disregarded.");
			packetIndex++;

		} else if (packets[packetIndex].size == currentTokens) {
			currentTokens = 0;
		} else {
			currentTokens -= packets[packetIndex].size;
		}

		seconds++;
	}
}

int main() {
	int choice = 1;

	while (choice != 0) {
		printf("==============================================");
		printf(
			"\n1. Leaky Bucket\n2. Token Bucket\n0. Exit\n\nChoose your "
			"option: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				leakyBucket();
				break;
			case 2:
				tokenBucket();
				break;
			case 0:
				break;
			default:
				printf("\nWrong option. Try again.");
				break;
		}
	}
	getchar();
	return 0;
}
