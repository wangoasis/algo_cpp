typedef int elementType;
#define infinity (30000)

#ifndef _BINQUEUE_H
#define _BINQUEUE_H

#define maxTrees (14)   /* Stores 2^14 -1 items */
#define maxCapacity (16383)

struct binNode;
typedef struct binNode *binTree;
struct collection;
typedef struct collection *binQueue;

binQueue init(void);
void destroy(binQueue);
binQueue makeEmpty(binQueue);
binQueue insert(elementType, binQueue);
elementType deleteMin(binQueue);
binQueue merge(binQueue, binQueue);
elementType findMin(binQueue);
int isEmpty(binQueue);
int isFull(binQueue);

#endif
