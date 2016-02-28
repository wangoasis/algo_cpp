#include "queue.h"
#include "fatal.h"
#include <stdlib.h>

#define minQueueSize (5)

struct queueRecord
{
  /* data */
  int capacity;
  int size;
  int front;
  int rear;
  elementType *array;
};

int isEmpty(queue q) {
  return q->size == 0;
}

int isFull(queue q) {
  return q->size == q->capacity;
}

queue createQueue(int maxElements) {
  if(maxElements < minQueueSize)
    Error("too small queue size");

  queue q;
  q = malloc(sizeof(struct queueRecord));
  if(!q)
    Error("out of memory");

  q->array = malloc(sizeof(struct queueRecord) * maxElements);
  if(!q->array)
    Error("out of memory");
  q->capacity = maxElements;
  q->size = 0;
  q->front = 1;
  q->rear = 0;

  return q;
}

void destroy(queue q) {
  if(!q) {
    free(q->array);
    free(q);
  }
}

static int succ(int index, queue q) {
  if(++index == q->capacity)
    return 0;
  return index;
}

void enqueue(elementType value, queue q) {
  if(isFull(q))
    Error("queue full");
  else {
    q->size++;
    q->rear = succ(q->rear, q);
    q->array[q->rear] = value;
  }
}

void dequeue(queue q) {
  if(isEmpty(q))
    Error("empty queue");
  else {
    q->size--;
    q->front = succ(q->front, q);
  }
}

elementType front(queue q) {
  if(!isEmpty(q))
    return q->array[q->front];
  Error("empty queue");
  return 0;
}

elementType frontAndDequeue(queue q) {
  if(isEmpty(q))
    Error("empty queue");
  else {
    elementType e = q->array[q->front];
    q->size--;
    q->front = succ(q->front, q);
    return e;
  }
}
