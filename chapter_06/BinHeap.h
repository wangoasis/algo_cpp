#ifndef _BINHEAP_H
#define _BINHEAP_H

typedef int elementType;
#define minData (-10000)

typedef int bool;
#define TURE 1
#define FALSE 0

struct heapStruct;
typedef struct heapStruct *priorityQuene;

priorityQuene init(int maxElements);
void destroy(priorityQuene H);
void makeEmpty(priorityQuene H);
void insert(elementType X, priorityQuene H);
elementType deleteMin(priorityQuene H);
elementType findMin(priorityQuene H);
bool isEmpty(priorityQuene H);
bool isFull(priorityQuene H);

#endif
