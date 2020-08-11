#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "linked_list.h"
#include "hash_table.h"

int main() {
	DirectAdressTable table = createDirectAddressTable();
	HashItem item0 = createHashItem(0, 'a');
	HashItem item1 = createHashItem(16, 'b');
	HashItem item2 = createHashItem(0, 'c');
	HashItem item3 = createHashItem(-1, 'd');
	HashItem item4 = createHashItem(30, 'a');
	int success;
	success = directAddressInsert(&table, &item0);
	if (success == 1) {
		printf("Inserted item with key %d\n", item0.key);
	}
	else {
		printf("Failed to insert item with key %d\n", item0.key);
	}
	success = directAddressInsert(&table, &item1);
	if (success == 1) {
		printf("Inserted item with key %d\n", item1.key);
	}
	else {
		printf("Failed to insert item with key %d\n", item1.key);
	}
	HashItem* searchedItem = directAddressSearch(&table, 0);
	if (searchedItem == NULL) {
		printf("Could not find item.\n");
	}
	else
	{
		printf("key: %d , c: %c", searchedItem->key, searchedItem->c);
	}
	return 0;
}