#ifndef HASH_TABLE
#define HASH_TABLE
#define HASH_TABLE_SIZE 20

typedef struct hashItem {
	int key;
	char c;
} HashItem;

// A table where each item is stored in it's own key.
// Keys must be unique.
typedef struct directAdressTable {
	int count; // Number of elemts currently in the table.
	HashItem* hashArray[HASH_TABLE_SIZE];
} DirectAdressTable;

HashItem createHashItem(int key, char c);

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

#endif // !HASH_TABLE