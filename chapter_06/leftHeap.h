typedef int elementType;

#ifndef _LEFTHEAP_H
#define _LEFTHEAP_H

struct treeNode;
typedef struct treeNode *priorityQueue;

priorityQueue init(void);
elementType findMin(priorityQueue);
priorityQueue deleteMin(priorityQueue);
int isEmpty(priorityQueue);
priorityQueue insert(elementType, priorityQueue);
priorityQueue merge(priorityQueue, priorityQueue);

#endif