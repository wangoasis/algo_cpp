#include "BinHeap.h"
#include "fatal.h"
#include <stdlib.h>

struct heapStruct {

    int capacity;
    int size;
    elementType *elements;
};

priorityQuene init(int maxElements) {
    
    priorityQuene H;

    H = malloc(sizeof(struct heapStruct));
    if(H == NULL)
        FatalError("Out of Memory Space");

    // Allocate the array plus one extra
    H->elements = malloc((maxElements+1) * sizeof(elementType));
    if(H->elements == NULL)
        FatalError("Out of Memory Space");

    H->capacity = maxElements;
    H->size = 0;
    H->elements[0] = minData;

    return H;
}

void insert(elementType X, priorityQuene H) {

    if(isFull(H)) {
        FatalError("Full!!!");
        return;
    }
    
    int i;
    for(i = ++H->size; H->elements[i/2] > X; i /= 2) 
        H->elements[i] = H->elements[i/2];

    H->elements[i] = X;
}

bool isFull(priorityQuene H) {

    return H->size == H->capacity;
}

void makeEmpty(priorityQuene H) {
    
    H->size = 0;
}

elementType findMin(priorityQuene H) {

    if(!isEmpty(H))
        return H->elements[1];
    Error("Empty!!!");
    return H->elements[0];
}

bool isEmpty(priorityQuene H) {

    return H->size == 0;
}

void destroy(priorityQuene H) {

    free(H->elements);
    free(H);
}

elementType deleteMin(priorityQuene H) {
    
    int i, child;
    elementType minElement, lastElement;

    if(isEmpty(H)) {
        Error("Empty!!!");
        return H->elements[0];
    }
    minElement = H->elements[1];
    lastElement = H->elements[H->size--];

    for(i = 1; i * 2 <= H->size; i = child ) {
        
        child = 2 * i; // left child
        if(child != H->size && H->elements[child + 1] < H->elements[child])
            // node i has two child and right child < left child
            child++;

        if(lastElement > H->elements[child])
            H->elements[i] = H->elements[child];
        else break;
    }
    H->elements[i] = lastElement;
    return minElement;
}
