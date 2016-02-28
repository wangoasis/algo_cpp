#include <stdio.h>
#include "stack.h"

int main( )
{
    stack s;
    int i;

    s = createStack(12);
    for(i = 0; i < 10; i++)
        push(i, s);

    while(!isEmpty( s ))
    {
        printf("%d\n", top(s));
        pop(s);
    }

    s = createStack(12);
    for(i = 0; i < 10; i++)
        push(i, s);
    topAndPop(s);

    destroy(s);
    return 0;
}
