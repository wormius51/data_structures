#ifndef LINKED_LIST
#define LINKED_LIST

typedef struct doubleLinkedNode {
	int key;
	struct doubleLinkedNode *next;
	struct doubleLinkedNode *previous;
	char c;
} DoubleLinkedNode;

typedef struct doubleLinkedList
{
	DoubleLinkedNode* head;
	DoubleLinkedNode* tail;
	int count; // The number of nodes.
} DoubleLinkedList;

DoubleLinkedNode createDoubleLinkedNode(int key, char c);

DoubleLinkedList createDoubleLinkedList();

// Inserts the node at the head of the list.
void listInsert(DoubleLinkedList* list, DoubleLinkedNode* node);

// Removes the node from the list.
void listDelete(DoubleLinkedList* list, DoubleLinkedNode* node);

// Prints every element in the list.
void printList(DoubleLinkedList* list);

// Returns the first element that has this key.
// If does not exist, returns NULL.
DoubleLinkedNode* listSearch(DoubleLinkedList* list, int key);

#endif // !LINKED_LIST

