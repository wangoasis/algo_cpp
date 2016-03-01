#include "hashSep.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>
#define maxTableSize (5)

struct listNode {
    
    elementType element;
    struct listNode *next;
};

typedef struct listNode *list;

struct hashTbl {
    
    int size;
    list *theLists;
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

hashTable init(int maxElements) {
    
    if(maxElements < maxTableSize) {
        Error("too small size");
        return NULL;
    }

    hashTable h;
    h = malloc(sizeof(struct hashTbl));
    if(!h)
        Error("out of space");

    h->size = nextPrime(maxElements);
    h->theLists = malloc(sizeof(list) * h->size);
    if(!h->theLists)
        Error("out of space");

    for(int i = 0; i < h->size; i++) {
    
        h->theLists[i] = malloc(sizeof(struct listNode));
        if(!h->theLists[i])
            Error("out of space");
        h->theLists[i]->next = NULL;
    }

    return h;
}

void destroyTable(hashTable h) {
    
    position temp;
    for(int i = 0; i < h->size; i++) {
        
        list l = h->theLists[i];
        while(!l) {
            
            temp = l->next;
            free(l);
            l = temp;
        }
    }

    free(h->theLists);
    free(h);
}

elementType retrieve(position p) {
    
    return p->element;
}

position find(elementType value, hashTable h) {
        
    list l = h->theLists[hash(value, h->size)];
    position p = l->next;

    while(p && (p->element != value)) 
        p = p->next;
    return p;
}

void insert(elementType value, hashTable h) {
    
    position p = find(value, h);
    if(!p) {
        
        position newNode = malloc(sizeof(struct listNode));
        if(!newNode)
            Error("out of space");
        list l = h->theLists[hash(value, h->size)];
        newNode->next = l->next;
        newNode->element = value;
        l->next = newNode;
    }
}

void delete(elementType value, hashTable h) {
        
    list l = h->theLists[hash(value, h->size)];
    position p1 = l;
    position p2 = l->next;
    while(p2 && (p2->element != value)) {
        p2 = p2->next;
        p1 = p1->next;
    }   
    if(!p2)
        printf("number to delete doesn't exists");
    else {
        p1->next = p2->next;
        free(p2);
    }
}
