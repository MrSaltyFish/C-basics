#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>	 // sleep()

struct packet {
	int data;
	char ack;
} p[50];

int numberOfFrames, frameSize;

void sender() {
	printf("\nEnter the number of frames: ");
	scanf("%d", &numberOfFrames);
	printf("Enter the frame size: ");
	scanf("%d", &frameSize);

	for (int i = 0; i < numberOfFrames; i++) {
		printf("Enter the data of frame #%d: ", i + 1);
		scanf("%d", &p[i].data);
		p[i].ack = 'y';
	}
}

void recvAck() {
	int droppedIndex = rand() % numberOfFrames;
	p[droppedIndex].ack = 'n';
}

void resend_sr() {
	for (int i = 0; i < numberOfFrames; i++) {
		if (p[i].ack == 'n') {
			printf("\nUnsuccessful transmission of Frame #%d: ", i + 1);
			printf("\nRetransmitting Frame #%d: ", i + 1);
			p[i].ack = 'y';
		}
	}
}

void resend_gb() {
	for (int i = 0; i < numberOfFrames; i++) {
		if (p[i].ack == 'n') {
			printf("\nUnsuccessful transmission of Frame #%d: Data: %d", i + 1,
				   p[i].data);
			int start = i;
			int end = numberOfFrames > (i + frameSize) ? (i + frameSize)
													   : numberOfFrames;
			for (int j = start; j < end; j++) {
				printf("\nRetransmitting Frame #%d: Data: %d", j + 1,
					   p[j].data);
				p[j].ack = 'y';
			}
		}
	}
}
void selectiveRepeat() {
	sender();
	recvAck();
	resend_sr();
}

void goBackN() {
	sender();
	recvAck();
	resend_gb();
}

int main() {
	int choice = 0;

	while (!choice) {
		printf(
			"\n1. Selective ARQ\n2. Go-Back-N\n0. Exit\n\nChoose your "
			"option: ");
		scanf("%d", &choice);
		switch (choice) {
			case 1:
				selectiveRepeat();
				break;
			case 2:
				goBackN();
				break;
			case 0:
				break;
			default:
				printf("\nWrong option. Try again.");
				break;
		}
	}

	return 0;
}
