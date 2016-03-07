#include "sPlayTree.h"
#include <stdio.h>
#define NumItems 500

int main( )
{
    sPlayTree T;
    sPlayTree P;
    int i;
    int j = 0;

    T = init( );
    T = makeEmpty( T );
    for( i = 0; i < NumItems; i++, j = ( j + 7 ) % NumItems )
        T = insert( j, T );
    printf("insertion finished\n");
  
    for( i = 0; i < NumItems; i++ )
    {
        T = find( i, T );
        if( retrieve( T ) != i )
            printf( "Error1 at %d\n", i );
    }

    printf( "delete even numbers\n" );

    for( i = 0; i < NumItems; i += 2 )
        T = delete( i, T );

    for( i = 1; i < NumItems; i += 2 )
    {
        T = find( i, T );
        if( retrieve( T ) != i )
            printf( "Error2 at %d\n", i );
    }

    for( i = 0; i < NumItems; i += 2 )
    {
        T = find( i, T );
        if( retrieve( T ) == i )
            printf( "Error3 at %d\n", i );
    }

    printf( "Min is %d\n", retrieve( T = findMin( T ) ) );
    printf( "Max is %d\n", retrieve( T = findMax( T ) ) );

    return 0;
}
