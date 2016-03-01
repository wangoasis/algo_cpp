#include "binomialQueue.h"
#include <stdio.h>

#define maxElements (100)

int main() {
    
  binQueue q;

  q = init();

  for(int i = 0; i < maxElements; i++)
    q = insert((i + 17)%maxElements, q);

  while(!isEmpty(q))
    printf("%d ", deleteMin(q));
  printf("\n");

  destroy(q);

  return 0;
}
