#include "tree.h"
#include <stdio.h>

#define maxNum (30)

int main() {

  searchTree tree;
  position p;
  int i;

  // test: create tree, insert
  tree = makeEmpty(NULL);
  for(i = 0; i < maxNum; i++) 
    tree = insert((i+7)%maxNum, tree);

  // test: find
  for(i = 0; i < maxNum; i++)
    if(find(i, tree) != NULL)
      printf("find %d \n", i);
    else
      printf("find error\n");

  // test: delete
  for(i = 0; i < maxNum; i += 2)
    tree = delete(i, tree);

  // test: inOrder and delete
  inOrder(tree);

  // test: findMin and findMax
  printf( "\nMin is %d, Max is %d\n", retrieve(findMin(tree)), retrieve(findMax(tree)));
}
