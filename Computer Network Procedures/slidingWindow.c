#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int numberOfFrames, randomDroppedFrame, frameSize;

struct frame {
	int data;
	char ack;
} frames[20];

int sender(void);
void recvack(void);
void resend_sr(void);
void goback(void);
void resend_gb(void);
void selective(void);

int main() {
	int c;
	do {
		printf("\n1. Selective Repeat ARQ\n2. Goback ARQ\n3. Exit");
		printf("\nYour Choice: ");
		scanf("%d", &c);
		switch (c) {
			case 1:
				selective();
				break;
			case 2:
				goback();
				break;
			case 3:
				exit(0);
				break;
			default:
				printf("\nInvalid choice. Please try again.\n");
				break;
		}
	} while (c != 3);
	getchar();
	return 0;
}

int sender(void) {
	int i = 0;
	printf("\nEnter the number of frames to be sent: ");
	scanf("%d", &numberOfFrames);
	printf("\nEnter the frame size: ");
	scanf("%d", &frameSize);
	for (i = 0; i < numberOfFrames; i++) {
		printf("\nEnter data for frame [%d]: ", i + 1);
		scanf("%d", &frames[i].data);
		frames[i].ack = 'y';
	}
}

void recvack(void) {
	randomDroppedFrame = rand() % numberOfFrames;
	frames[randomDroppedFrame].ack = 'n';
	for (int i = 0; i < numberOfFrames; i++) {
		if (frames[i].ack == 'n') {
			printf("\nThe frame number %d is not received.", i + 1);
		}
	}
}

void resend_sr(void) {
	printf("Sending...");

	frames[randomDroppedFrame].ack = 'y';
	printf("\nFrame #%d with data %d was resent.", (randomDroppedFrame + 1),
		   frames[randomDroppedFrame].data);
}

void goback(void) {
	sender();
	recvack();
	resend_gb();
}

void resend_gb(void) {
	int start = randomDroppedFrame;
	int end = (numberOfFrames >= (start + frameSize)) ? (start + frameSize)
													  : numberOfFrames;
	printf("\nResending.....");
	for (int i = start; i < end; i++) {
		frames[i].ack = 'y';
		printf("\nFrame %d was resent", i + 1);
	}
}

void selective(void) {
	sender();
	recvack();
	resend_sr();
}