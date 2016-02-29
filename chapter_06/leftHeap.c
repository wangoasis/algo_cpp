#include "leftHeap.h"
#include "fatal.h"

struct treeNode {

  elementType element;
  priorityQueue leftChild;
  priorityQueue rightChild;
  int npl;
};

priorityQueue init(void) {

  return NULL;
}

elementType findMin(priorityQueue p) {

  if(!isEmpty(p))
    return p->element;
  Error("empty priorityQueue");
  return 0;
}

int isEmpty(priorityQueue p) {

  return p == NULL;
}

// swap the left child with right child to macth the requirement that 
// left npl >= right npl
static void swapChildren(priorityQueue p) {

  priorityQueue temp;

  temp = p->leftChild;
  p->leftChild = p->rightChild;
  p->rightChild = temp;
}

static priorityQueue merge1(priorityQueue p1, priorityQueue p2) {

  if(!p1->leftChild) {

    // if p1 don't have a left child, it's impossible for p1 to have a right child
    p1->leftChild = p2;
  } else {

    // merge p2 to p1's left child
    p1->rightChild = merge(p1->rightChild, p2);
    if(p1->leftChild->npl < p1->rightChild->npl)
      swapChildren(p1);

    p1->npl = p1->rightChild->npl + 1;
  }
  return p1;
}

// p2's root should be less than p1's root, 
// else, execute merge(p2, p1)
priorityQueue merge(priorityQueue p1, priorityQueue p2) {

  if(!p1)
    return p2;
  if(!p2)
    return p1;
  if(p1->element > p2->element)
    return merge1(p2, p1);
  else
    return merge1(p1, p2);
}

// insert an element to a priorityQueue p is like:
// merge a priorityQueue(single node) with p 
priorityQueue insert(elementType value, priorityQueue p) {

  priorityQueue newNode;
  newNode = malloc(sizeof(struct treeNode));
  if(!newNode)
    Error("out of space");
  newNode->leftChild = newNode->rightChild = NULL;
  newNode->npl = 0;
  newNode->element = value;
  p = merge(p, newNode);
  return p;
}

priorityQueue deleteMin(priorityQueue p) {

  if(isEmpty(p))
    Error("empty priorityQueue");

  priorityQueue left = p->leftChild;
  priorityQueue right = p->rightChild;
  return merge(left, right);
}
