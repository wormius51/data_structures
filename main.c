#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "linked_list.h"
#include "table.h"


#define NUMBER_OF_NODES 30

int main() {
	DoubleLinkedNode nodes[NUMBER_OF_NODES];
	for (int i = 0; i < NUMBER_OF_NODES; i++)
	{
		nodes[i] = createDoubleLinkedNode(i, 'a' + i);
	}
	ChainedHashTable table = createChainedHashTable();
	for (int i = 0; i < NUMBER_OF_NODES; i++)
	{
		chainedHashTableInsert(&table, &(nodes[i]));
	}
	DoubleLinkedNode* searchedNode = chainedHashTableSearch(&table, 21);
	if (searchedNode == NULL) {
		printf("Node was not found.");
	}
	else
	{
		printf("c: %c", searchedNode->c);
	}

	return 0;
}