#include "binomialQueue.h"
#include "fatal.h"

struct binNode
{
  elementType element;
  binTree  leftChild;
  binTree  nextSibling;
};

struct collection
{
  int currentSize;
  binTree theTrees[maxTrees];
};

binQueue init(void)
{
  binQueue H;
  int i;

  H = malloc(sizeof(struct collection));
  if(H == NULL)
    FatalError("Out of space!!!");
  H->currentSize = 0;
  for(i = 0; i < maxTrees; i++)
    H->theTrees[i] = NULL;
  return H;
}

static void destroyTree(binTree T)
{
  if(T != NULL)
  {
    destroyTree(T->leftChild);
    destroyTree(T->nextSibling);
    free(T);
  }
}

void destroy(binQueue H)
{
  int i;

  // destroy every tree
  for(i = 0; i < maxTrees; i++)
    destroyTree(H->theTrees[i]);
}

binQueue makeEmpty(binQueue H)
{
  int i;

  destroy(H);
  for(i = 0; i < maxTrees; i++)
    H->theTrees[i] = NULL;
  H->currentSize = 0;

  return H;
}

// insert an element is like:
// merge a binQueue(one node) with a binQueue
binQueue insert(elementType Item, binQueue H)
{
  binTree newnode;
  binQueue OneItem;

  newnode = malloc(sizeof(struct binNode));
  if(newnode == NULL)
    FatalError("Out of space!!!");
  newnode->leftChild = newnode->nextSibling = NULL;
  newnode->element = Item;

  OneItem = init();
  OneItem->currentSize = 1;
  OneItem->theTrees[0] = newnode;

  return merge(H, OneItem);
}

elementType deleteMin(binQueue H)
{
  int i, j;
  int minTree;   // the tree with the minimum item 
  binQueue deletedQueue;
  binTree deletedTree, oldroot;
  elementType minItem;

  if(isEmpty(H))
  {
    Error("Empty binomial queue");
    return -infinity;
  }

  minItem = infinity;
  for(i = 0; i < maxTrees; i++)
  {
    if(H->theTrees[i] &&
      H->theTrees[i]->element < minItem)
    {
      minItem = H->theTrees[i]->element;
      minTree = i;
    }
  }

  deletedTree = H->theTrees[minTree];
  oldroot = deletedTree;
  deletedTree = deletedTree->leftChild;
  free(oldroot);

  deletedQueue = init();
  deletedQueue->currentSize = (1 << minTree) - 1;
  for(j = minTree - 1; j >= 0; j--)
  {
    deletedQueue->theTrees[j] = deletedTree;
    deletedTree = deletedTree->nextSibling;
    deletedQueue->theTrees[j]->nextSibling = NULL;
  }

  H->theTrees[minTree] = NULL;
  H->currentSize -= deletedQueue->currentSize + 1;

  merge(H, deletedQueue);
  return minItem;
}

elementType findMin(binQueue H)
{
  int i;
  elementType minItem;

  if(isEmpty(H))
  {
    Error("Empty binomial queue");
    return 0;
  }

  minItem = infinity;
  for(i = 0; i < maxTrees; i++)
  {
    if(H->theTrees[i] &&
          H->theTrees[i]->element < minItem)
      minItem = H->theTrees[i]->element;
  }

  return minItem;
}

int isEmpty(binQueue H)
{
  return H->currentSize == 0;
}

int isFull(binQueue H)
{
  return H->currentSize == maxCapacity;
}

binTree combineEqualTrees(binTree T1, binTree T2)
{
  if(T1->element > T2->element)
    return combineEqualTrees(T2, T1);
  T2->nextSibling = T1->leftChild;
  T1->leftChild = T2;
  return T1;
}

binQueue merge(binQueue H1, binQueue H2)
{
  binTree T1, T2, carry = NULL;
  int i, j;

  if(H1->currentSize + H2->currentSize > maxCapacity)
    Error("merge would exceed maxCapacity");

  H1->currentSize += H2->currentSize;
  for(i = 0, j = 1; j <= H1->currentSize; i++, j *= 2)
  {
    T1 = H1->theTrees[i]; T2 = H2->theTrees[i];

    switch(!!T1 + 2 * !!T2 + 4 * !!carry)
    {
      case 0: // no trees 
      case 1: // Only H1 
        break; // needn't do anything 
      case 2: // Only H2 
        H1->theTrees[i] = T2;
        H2->theTrees[i] = NULL;
        break;
      case 4: // Only carry 
        H1->theTrees[i] = carry;
        carry = NULL;
        break;
      case 3: // H1 and H2 
        carry = combineEqualTrees(T1, T2);
        H1->theTrees[i] = H2->theTrees[i] = NULL;
        break;
      case 5: // H1 and carry 
        carry = combineEqualTrees(T1, carry);
        H1->theTrees[i] = NULL;
        break;
      case 6: // H2 and carry 
        carry = combineEqualTrees(T2, carry);
        H2->theTrees[i] = NULL;
        break;
      case 7: // All three 
        H1->theTrees[i] = carry;
        carry = combineEqualTrees(T1, T2);
        H2->theTrees[i] = NULL;
        break;
    }
  }
  return H1;
}
