typedef int elementType;
#define infinity (10000)
#define negInfinity (-10000)

#ifndef _SPLAYTREE_H
#define _SPLAYTREE_H

struct sPlayNode;
typedef struct sPlayNode *sPlayTree;

sPlayTree init(void);
sPlayTree makeEmpty(sPlayTree);
sPlayTree find(elementType, sPlayTree);
sPlayTree findMax(sPlayTree);
sPlayTree findMin(sPlayTree);
elementType retrieve(sPlayTree);
sPlayTree insert(elementType, sPlayTree);
sPlayTree delete(elementType, sPlayTree);
void inOrder(sPlayTree);

#endif
