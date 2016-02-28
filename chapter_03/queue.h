typedef int elementType;

#ifndef _QUEUE_H
#define _QUEUE_H

struct queueRecord;
typedef struct queueRecord *queue;

int isEmpty(queue);
int isFull(queue);
queue createQueue(int);
void destroy(queue);
void enqueue(elementType, queue);
void dequeue(queue);
elementType front(queue);
elementType frontAndDequeue(queue);

#endif