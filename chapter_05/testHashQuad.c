#include "hashQuad.h"
#include <stdio.h>

#define NumItems (400)

int main( )
{
    hashTable H;
    position P;
    int i;
    int j = 0;
    int currentSize = 21;

    H = init(currentSize);

    for(i = 0; i < NumItems; i++, j += 71 ) {
        if(i > currentSize / 2 ) {
             H = rehash( H );
             printf( "Rehashing...\n" );
             currentSize *= 2;
        }
        insert( j, H );
    }

    for( i = 0, j = 0; i < NumItems; i++, j += 71 )
         if(retrieve(find(j, H),H) != j)
             printf( "Error at %d\n", j );

    return 0;
}
