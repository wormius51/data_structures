#include <stdio.h>
#include "linked_list.h"

DoubleLinkedNode createDoubleLinkedNode(int key, char c) {
	DoubleLinkedNode node;
	node.c = c;
	node.key = key;
	node.next = NULL;
	node.previous = NULL;
	return node;
}

DoubleLinkedList createDoubleLinkedList() {
	DoubleLinkedList list;
	list.count = 0;
	list.head = NULL;
	list.tail = NULL;
	return list;
}

// Inserts the node at the head of the list.
void listInsert(DoubleLinkedList* list, DoubleLinkedNode* node) {
	node->next = list->head;
	if (list->head == NULL) {
		list->tail = node;
	}
	else
	{
		list->head->previous = node;
	}
	list->head = node;
	node->previous = NULL;
	list->count++;
}

// Removes the node from the list.
void listDelete(DoubleLinkedList* list, DoubleLinkedNode* node) {
	// If this node is the head,
	// turn the next node into the head.
	if (node == list->head) {
		if (node->next != NULL) {
			node->next->previous = NULL;
			list->head = node->next;
		}
	}
	else if (node == list->tail) {
		if (node->previous != NULL) {
			node->previous->next = NULL;
			list->tail = node->previous;
		}
	}
	else
	{
		node->next->previous = node->previous;
		node->previous->next = node->next;
	}
	list->count--;
}

// Prints every element in the list.
void printList(DoubleLinkedList* list) {
	printf("The list has %d elements:\n", list->count);
	DoubleLinkedNode* node = list->head;
	while (node != NULL)
	{
		printf("%d\n", node->key);
		node = node->next;
	}
}

// Returns the first element that has this key.
// If does not exist, returns NULL.
DoubleLinkedNode* listSearch(DoubleLinkedList* list, int key) {
	DoubleLinkedNode* node = list->head;
	while (node != NULL) {
		if (node->key == key)
			return node;
		node = node->next;
	}
	return NULL;
}