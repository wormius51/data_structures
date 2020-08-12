#ifndef CHAINED_HASH_TABLE
#define CHAINED_HASH_TABLE
#include "table.h"
#include "linked_list.h"

typedef struct chainedHashTable {
	DoubleLinkedList lists[TABLE_SIZE];
	int count;
} ChainedHashTable;

ChainedHashTable createChainedHashTable();

// Inserts the item (or node) to the table.
void chainedHashTableInsert(ChainedHashTable* table, DoubleLinkedNode* item);

// Removes the item (or node) from the table.
void chainedHashTableDelete(ChainedHashTable* table, DoubleLinkedNode* item);

// Returns the node with the given key.
// If not found, returns NULL.
DoubleLinkedNode* chainedHashTableSearch(ChainedHashTable* table, int key);

#endif // !CHAINED_HASH_TABLE

