#include "fatal.h"
#include "hashQuad.h"
#include <stdlib.h>

#define minTableSize (10)

enum kindOfEntry {
    Legitimate,
    Empty     ,
    Deleted  
};  

struct hashEntry {
    
    elementType element;
    enum kindOfEntry info;
};

typedef struct hashEntry tableCell;

struct hashTbl {
    
    int size;
    tableCell *theCells;
};

// test whether an odd number is prime
static int isPrime(int num) {
    
    for(int i = 3; i * i < num; i += 2) {
        
        if(num % i == 0)
            return 0;
    }
    return 1;
}

static int nextPrime(int num) {
    
    if(num % 2 == 0)
        num++;

    for( ; ; num += 2) {
    
        if(isPrime(num))
            break;
    }

    return num;
}

static int hash(int value, int size) {
    
    return value % size;
}

hashTable init(int maxSize) {
    
    if(maxSize < minTableSize) {
        
        printf("%d\n", maxSize); 
        Error("too small size");
        return NULL;
    }

    hashTable h;
    h = malloc(sizeof(struct hashTbl));
    if(!h)
        Error("out of space");

    h->size = nextPrime(maxSize);
    h->theCells = malloc(sizeof(tableCell) * h->size);
    if(!h->theCells)
        Error("out of space");

    for(int i = 0; i < maxSize; i++) 
        h->theCells[i].info = Empty;

    return h;
}

position find(elementType value, hashTable h) {
    
    position current;
    int collision;

    collision = 0;
    current = hash(value, h->size);
    while(h->theCells[current].info != Empty && 
          h->theCells[current].element != value) {
        current += 2 * ++collision - 1;
        if(current >= h->size)
            current -= h->size;
    }

    return current;
}

void destroyTable(hashTable h) {
    
    if(!h) {

        free(h->theCells);
        free(h);
    }
}

elementType retrieve(position p, hashTable h) {
    
    return h->theCells[p].element;
}

void insert(elementType value, hashTable h) {
    
    position pos = find(value, h);
    if(h->theCells[pos].info != Legitimate) {
        
        h->theCells[pos].info = Legitimate;
        h->theCells[pos].element = value;
    }
}

hashTable rehash(hashTable h) {
    
    int i, oldSize;
    tableCell *oldCells;

    oldCells = h->theCells;
    oldSize = h->size;

    h = init(2 * oldSize);
    for( i = 0; i < oldSize; i++) {
        if( oldCells[i].info == Legitimate)
            insert(oldCells[i].element, h);
    }

    free(oldCells);

    return h;
}
