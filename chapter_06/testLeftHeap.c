#include "leftHeap.h"
#include <stdio.h>

#define MaxSize (100)

int main() {

  priorityQueue p;
  int i, j;

  p = init();
  for(i = 0, j = MaxSize / 2; i < MaxSize; i++, j = (j + 17) % MaxSize)
    p = insert(j, p);

  j = 0;
  while(!isEmpty(p))
    if(findMin(p) == j++) {
      printf( " DeleteMin, %d\n", j);
      p= deleteMin(p);
  }
  printf( "Done...\n" );
  return 0;
}
