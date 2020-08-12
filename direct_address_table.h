#ifndef DIRECT_ADDRESS_TABLE
#define DIRECT_ADDRESS_TABLE
#include "table.h"

// A table where each item is stored in it's own key.
// Keys must be unique.
typedef struct directAdressTable {
	int count; // Number of elemts currently in the table.
	HashItem* hashArray[TABLE_SIZE];
} DirectAdressTable;

DirectAdressTable createDirectAddressTable();

// Inserts the item to the table and returns 1. If the cell is already taken
// or the key is out of bounds, returns 0 instead.
int directAddressInsert(DirectAdressTable* table, HashItem* item);

// Removes the item from the table and returns 1. If the item was not found
// or the key is out of bounds, returns 0 instead.
int directAddressDelete(DirectAdressTable* table, HashItem* item);

// Returns the item with this key.
// If there is no such item, returns NULL.
HashItem* directAddressSearch(DirectAdressTable* table, int key);

#endif // !DIRECT_ADDRESS_TABLE

