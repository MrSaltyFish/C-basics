// Distance Vector Algo

#include <stdio.h>
#define MAX_NODES 10
#define INF 9999

typedef struct {
	int cost[MAX_NODES];  // Cost to reach each node
	int from[MAX_NODES];  // From which node the cost is calculated
} DistanceTable;

void distanceVectorRouting(int nodes, int costMatrix[MAX_NODES][MAX_NODES]) {
	DistanceTable table[MAX_NODES];
	int i, j, k;

	// Initialize distance table
	for (i = 0; i < nodes; i++) {
		for (j = 0; j < nodes; j++) {
			table[i].cost[j] = costMatrix[i][j];
			table[i].from[j] = j;
		}
	}

	int updated;
	do {
		updated = 0;
		// Update the distance table
		for (i = 0; i < nodes; i++) {
			for (j = 0; j < nodes; j++) {
				for (k = 0; k < nodes; k++) {
					int currentCost = table[i].cost[j];
					int newCost = costMatrix[i][k] + table[k].cost[j];

					if (currentCost > newCost) {
						currentCost = newCost;
						table[i].from[j] = k;
						updated = 1;
					}
				}
			}
		}
	} while (updated);

	// Print final distance vectors
	for (i = 0; i < nodes; i++) {
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
	int nodes, i, j;
	int costMatrix[MAX_NODES][MAX_NODES];

	printf("Enter the number of nodes: ");
	scanf("%d", &nodes);

	printf("Enter the cost matrix (enter %d for infinity):\n", INF);
	for (i = 0; i < nodes; i++) {
		for (j = 0; j < nodes; j++) {
			scanf("%d", &costMatrix[i][j]);
			if (i == j) {
				costMatrix[i][j] = 0;  // Cost to self is 0
			}
		}
	}

	distanceVectorRouting(nodes, costMatrix);

	return 0;
}
