#include "stack.h"
#include <stdio.h>

// Creates a stack and returns it.
Stack createStack() {
	Stack stack;
	stack.top = -1;
	return stack;
}

// Returns 1 if the stack is empty and 0 if not.
int isStackEmpty(Stack* stackptr) {
	if (stackptr == NULL) {
		printf("The stack was not found.");
		return 1;
	}
	if (stackptr->top < 0)
		return 1;
	return 0;
}

// Pushes the element to the top of the stack.
// Returns 1 if secceeded. 0 If not.
int push(Stack* stackptr, char c) {
	if (stackptr == NULL) {
		printf("Null pointer to stack.");
		return 0;
	}
	if (stackptr->top + 1 >= STACK_CAPACITY) {
		printf("Stack Overflow");
		return 0;
	}
	stackptr->top++;
	stackptr->memory[stackptr->top] = c;
	
	return 1;
}

// Removes the top element from the stack and returns it.
char pop(Stack* stackptr) {
	if (isStackEmpty(stackptr) == 1) {
		printf("Stack Underflow.");
		return NULL;
	}
	char c = stackptr->memory[stackptr->top];
	stackptr->memory[stackptr->top] = NULL;
	stackptr->top--;
	return c;
}