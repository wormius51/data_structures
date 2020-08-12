#include <stdio.h>
#include "hash.h"
#include <math.h>

HashItem createHashItem(int key, char c) {
	HashItem item;
	item.key = key;
	item.c = c;
	return item;
}

// Generates a an index form the key. 
// Uses multiplicative hashing.
unsigned multiplicativeHash(int key) {
	return floor(TABLE_SIZE *  (key * HASH_CONSTANT - floor(key * HASH_CONSTANT)));
}