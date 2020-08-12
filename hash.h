#ifndef HASH
#define TABLE_SIZE 20
#define HASH
#define HASH_CONSTANT 0.3

typedef struct hashItem {
	int key;
	char c;
} HashItem;

HashItem createHashItem(int key, char c);

// Generates a an index form the key. 
// Uses multiplicative hashing.
unsigned multiplicativeHash(int key);

#endif // !HASH
