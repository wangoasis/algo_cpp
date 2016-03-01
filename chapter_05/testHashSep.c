#include "hashSep.h"
#include <stdio.h>

int main() {
    
    hashTable h;

    h = init(10);
//    printf("size is %d\n", h->size);

    for(int i = 1; i < 20; i++) 
        insert(i*i, h);

    if(find(11 * 11, h))
        printf("11*11 found\n");

    delete(11 * 11, h);

    for(int i = 1; i < 20; i += 2)
        if(!find(i * i, h))
            printf("%d deleted\n", i * i);
        else
            printf("%d found\n", i * i);

    destroyTable(h);
    return 0;

}   
