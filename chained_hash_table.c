#include <stdio.h>
#include "hash.h"
#include "chained_hash_table.h"

ChainedHashTable createChainedHashTable() {
	ChainedHashTable table;
	table.count = 0;
	for (int i = 0; i < TABLE_SIZE; i++) {
		table.lists[i] = createDoubleLinkedList();
	}
	return table;
}

// Inserts the item (or node) to the table.
void chainedHashTableInsert(ChainedHashTable* table, DoubleLinkedNode* item) {
	if (item == NULL)
		return;
	unsigned hash = multiplicativeHash(item->key);
	listInsert(&(table->lists[hash]), item);
}

// Removes the item (or node) from the table.
void chainedHashTableDelete(ChainedHashTable* table, DoubleLinkedNode* item) {
	if (item == NULL)
		return;
	unsigned hash = multiplicativeHash(item->key);
	listDelete(&(table->lists[hash]), item);
}

// Returns the node with the given key.
// If not found, returns NULL.
DoubleLinkedNode* chainedHashTableSearch(ChainedHashTable* table, int key) {
	unsigned hash = multiplicativeHash(key);
	DoubleLinkedNode* node = listSearch(&(table->lists[hash]), key);
	return node;
}