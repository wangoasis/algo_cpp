#include "tree.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>

struct treeNode {
  /* data */
  elementType element;
  searchTree leftChild;
  searchTree rightChild;
};

searchTree makeEmpty(searchTree tree) {

  if(tree != NULL) {
    makeEmpty(tree->leftChild);
    makeEmpty(tree->rightChild);
    free(tree);
  }

  return NULL;
}

position find(elementType value, searchTree tree) {

  if(tree == NULL)
    return NULL;
  if(value < tree->element)
    return find(value, tree->leftChild);
  else if(value > tree->element)
    return find(value, tree->rightChild);
  else
    return tree;
}

position findMax(searchTree tree) {

  if(tree == NULL)
    return NULL;
  else if(tree->rightChild == NULL)
    return tree;
  else
    return findMax(tree->rightChild);
}

position findMin(searchTree tree) {

  if(tree == NULL)
    return NULL;
  else if(tree->leftChild == NULL)
    return tree;
  else
    return findMin(tree->leftChild);
}

searchTree insert(elementType value, searchTree tree) {

  if(tree == NULL) {

    tree = malloc(sizeof(struct treeNode));
    if(tree == NULL)
      Error("Out of Space!!!");
    else {
      tree->element = value;
      return tree;
    }
  } else if(value < tree->element) {

    tree->leftChild = insert(value, tree->leftChild);
  } else if(value > tree->element) {

    tree->rightChild = insert(value, tree->rightChild);
  }

  return tree;
}

searchTree delete(elementType value, searchTree tree) {

  position temp;

  if(tree == NULL)
    Error("element not found!!!");
  else if(value < tree->element) {
    tree->leftChild = delete(value, tree->leftChild);
  } else if(value > tree->element) {
    tree->rightChild = delete(value, tree->rightChild);
  } else {
    if(tree->leftChild && tree->rightChild) {
      temp = findMin(tree->rightChild);
      tree->element = temp->element;
      tree->rightChild = delete(tree->element, temp->rightChild);
    } else {

      temp = tree;
      if(!tree->leftChild)
        tree = tree->rightChild;
      else if(!tree->rightChild)
        tree = tree->leftChild;
      free(temp);
    }
  }

  return tree;
}

elementType retrieve(position p) {

  return p->element;
}

void inOrder(searchTree tree) {

  if(tree) {
    inOrder(tree->leftChild);
    printf("%d, ", tree->element);
    inOrder(tree->rightChild);
  }
}
