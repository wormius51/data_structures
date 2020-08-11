#ifndef QUEUE
#define QUEUE

#define QUEUE_CAPACITY 20

// A structure where the first element to get in is the first to get out.
typedef struct queue
{
	char memory[QUEUE_CAPACITY]; // A pointer to the momory address of the data.
	int head;
	int tail;
} Queue;

Queue createQueue();

// Enteres an element to the tail of the queue.
int enqueue(Queue* queue, char c);

// Removes an element from the head of the queue and returns it.
char dequeue(Queue* queue);

#endif // QUEUE

