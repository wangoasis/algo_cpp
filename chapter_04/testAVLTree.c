#include "avlTree.h"
#include <stdio.h>

#define maxElements (50)

int main() {
    
    avlTree tree;

    for(int i = 0; i < maxElements / 2; i++)
        tree = insert((i+17)%maxElements, tree);

    elementType min = retrieve(findMin(tree));
    printf("%d ", min);

    inOrder(tree);
    printf("\n");

    return 0;
}
