#include <stdio.h>
#include "direct_address_table.h"

DirectAdressTable createDirectAddressTable() {
	DirectAdressTable table;
	table.count = 0;
	// Inserting NULL in all the cells to indicate they are empty.
	for (int i = 0; i < TABLE_SIZE; i++) {
		table.hashArray[i] = NULL;
	}
	return table;
}

// If this is a valid item for a DirectAdressTable, returns 1.
// Otherwise, returns 0.
int isValidDirectAdressItem(HashItem* item) {
	if (item == NULL)
		return 0;
	if (item->key < 0)
		return 0;
	if (item->key > TABLE_SIZE - 1)
		return 0;
	return 1;
}

// Inserts the item to the table and returns 1. If the cell is already taken
// or the key is out of bounds, returns 0 instead.
int directAddressInsert(DirectAdressTable* table, HashItem* item) {
	if (isValidDirectAdressItem(item) == 0)
		return 0;
	if (table->hashArray[item->key] != NULL)
		return 0;
	table->hashArray[item->key] = item;
	table->count++;
	return 1;
}

// Removes the item from the table and returns 1. If the item was not found
// or the key is out of bounds, returns 0 instead.
int directAddressDelete(DirectAdressTable* table, HashItem* item) {
	if (isValidDirectAdressItem(item) == 0)
		return 0;
	if (table->hashArray[item->key] == item) {
		table->hashArray[item->key] = NULL;
		table->count--;
		return 1;
	}
	return 0;
}

// Returns the item with this key.
// If there is no such item, returns NULL.
HashItem* directAddressSearch(DirectAdressTable* table, int key) {
	if (key < 0)
		return NULL;
	if (key > TABLE_SIZE - 1)
		return NULL;
	return table->hashArray[key];
}