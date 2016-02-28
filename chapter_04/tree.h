typedef int elementType;

#ifndef _TREE_H
#define _TREE_H

struct treeNode;
typedef struct treeNode *searchTree;
typedef struct treeNode *position;

searchTree makeEmpty(searchTree);
position find(elementType, searchTree);
position findMax(searchTree);
position findMin(searchTree);
searchTree insert(elementType, searchTree);
searchTree delete(elementType, searchTree);
elementType retrieve(position);
void inOrder(searchTree);

#endif