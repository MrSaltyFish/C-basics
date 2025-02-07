#include <stdio.h>
#define MAX_NODES 10
#define INF 9999

typedef struct {
	int cost[MAX_NODES];
	int from[MAX_NODES];
} DistanceTable;

void DistanceVectorAlgorithm(int nodes, int costMatrix[MAX_NODES][MAX_NODES]) {
	DistanceTable table[MAX_NODES];
	int j;
	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			table[i].cost[j] = costMatrix[i][j];
			table[i].from[j] = j;
			if (i == j) {
				table[i].cost[j] = 0;
			}
		}
	}

	for (int i = 0; i < nodes; i++) {
		for (int j = 0; j < nodes; j++) {
			for (int k = 0; k < nodes; k++) {
				int currentDist = table[i].cost[j];
				int newDist = table[i].cost[k] + table[k].cost[j];

				if (newDist < currentDist) {
					table[i].cost[j] = newDist;
					table[i].from[j] = k;
				}
			}
		}
	}

	for (int i = 0; i < nodes; i++) {
		printf("Routing Table for Node %d:\n", i + 1);
		printf("Dest\tNext Hop\tCost\n");
		for (j = 0; j < nodes; j++) {
			printf("%d\t%d\t\t%d\n", j + 1, table[i].from[j] + 1,
				   table[i].cost[j]);
		}
		printf("\n");
	}
}

int main() {
	int n;
	int costMatrix[MAX_NODES][MAX_NODES];

	printf("Enter the number of nodes: ");
	scanf("%d", &n);

	printf("Enter the cost matrix: ");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &costMatrix[i][j]);
		}
	}
	DistanceVectorAlgorithm(n, costMatrix);
	getchar();
	return 0;
}