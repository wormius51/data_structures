#ifndef STACK
#define STACK

#define STACK_CAPACITY 20

// A structure for storing a row of elements.
typedef struct stack
{
	char memory[STACK_CAPACITY]; // A pointer to the momory address of the data.
	int top; // The index in the stack of the last element to enter it. -1 if empty.
	
} Stack;

// Creates a stack and returns it.
Stack createStack();

// Returns 1 if the stack is empty and 0 if not.
int isStackEmpty(Stack* stackptr);

// Pushes the element to the top of the stack.
// Returns 1 if secceeded. 0 If not.
int push(Stack* stackptr, char c);

// Removes the top element from the stack and returns it.
char pop(Stack* stackptr);

#endif // !STACK

