typedef int elementType;

#ifndef _AVLTREE_H
#define _AVLTREE_H

struct avlNode;
typedef struct avlNode *position;
typedef struct avlNode *avlTree;

avlTree makeEmpty(avlTree);
position find(elementType, avlTree);
position findMin(avlTree);
position findMax(avlTree);
avlTree insert(elementType, avlTree);
//avlTree delete(elementType, avlTree);
elementType retrieve(position);
void inOrder(avlTree);

#endif
