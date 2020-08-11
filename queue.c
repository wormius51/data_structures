#include "queue.h"
#include <stdio.h>

Queue createQueue() {
	Queue queue;
	queue.head = 0;
	queue.tail = 0;
	return queue;
}

// Enteres an element to the tail of the queue.
int enqueue(Queue* queue, char c) {
	queue->memory[queue->tail] = c;
	if (queue->tail >= QUEUE_CAPACITY - 1)
		queue->tail = 0;
	else
		queue->tail++;
}

// Removes an element from the head of the queue and returns it.
char dequeue(Queue* queue) {
	char c = queue->memory[queue->head];
	if (queue->head >= QUEUE_CAPACITY - 1)
		queue->head = 0;
	else
		queue->head++;
	return c;
}