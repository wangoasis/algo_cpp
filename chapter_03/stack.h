typedef int elementType;

#ifndef _STACK_H
#define _STACK_H

struct stackRecord;
typedef struct stackRecord *stack;

stack createStack(int);
int isEmpty(stack);
int isFull(stack);
void destroy(stack);
void makeEmpty(stack);
void push(elementType, stack);
elementType top(stack);
void pop(stack);
elementType topAndPop(stack);

#endif