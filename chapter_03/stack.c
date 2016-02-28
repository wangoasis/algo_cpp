#include "stack.h"
#include "fatal.h"
#include <stdlib.h>

#define MinElements (5)
#define EmptyStackTop (-1)

struct stackRecord
{
  /* data */
  int capacity;
  int topOfStack;
  elementType *array;
};

stack createStack(int maxElements) {

  if(maxElements < MinElements)
    Error("too small stack size\n");

  stack s;
  s = malloc(sizeof(struct stackRecord));
  if(!s)
    Error("out of memory\n");

  s->array = malloc(sizeof(struct stackRecord) * maxElements);
  if(!s->array)
    Error("out of memory\n");
  s->capacity = maxElements;
  makeEmpty(s);

  return s;
}

void destroy(stack s) {
  if(!s) {
    free(s->array);
    free(s);
  }
}

void makeEmpty(stack s) {
    s->topOfStack = EmptyStackTop;
}

int isEmpty(stack s) {
  return s->topOfStack == EmptyStackTop;
} 

int isFull(stack s) {
  return s->topOfStack + 1 == s->capacity;
}

elementType top(stack s) {
  return s->array[s->topOfStack];
}

void push(elementType value, stack s) {
  if(isFull(s))
    Error("out of memory");
  else
    s->array[++s->topOfStack] = value;
}

void pop(stack s) {
  if(isEmpty(s))
    Error("empty stack");
  else
    s->topOfStack--;
}

elementType topAndPop(stack s) {
  if(!isEmpty(s))
    return s->array[s->topOfStack--];
  Error("empty stack");
  return 0;
}
