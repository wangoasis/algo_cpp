#include <stdio.h>
#include "queue.h"

int main( )
{
    queue Q;
    int i;

    Q = createQueue(12);

    for(i = 0; i < 10; i++)
        enqueue(i, Q);

    while(!isEmpty(Q))
    {
        printf( "%d\n", front(Q));
        dequeue( Q );
    }

    destroy(Q);
    return 0;
}
