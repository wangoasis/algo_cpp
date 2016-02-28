#include "BinHeap.h"
#include <stdio.h>

#define MaxSize (100)

int main( )
{
    priorityQuene H;
    int i, j;

    H = init( MaxSize );
    for( i=0, j=MaxSize/2; i<MaxSize; i++, j=( j+71)%MaxSize )
        insert( j, H );

    j = 0;
    while( !isEmpty( H ) )
        printf( "DeleteMin, %d\n", deleteMin(H));
    printf( "Done...\n" );
    return 0;
}
