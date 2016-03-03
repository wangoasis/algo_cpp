typedef int elementType;

#ifndef _HASHQUAD_H
#define _HASHQUAD_H 

typedef unsigned int index;
typedef index position;

struct hashTbl;
typedef struct hashTbl *hashTable;

hashTable init(int);
void destroyTable(hashTable);
position find(elementType, hashTable);
void insert(elementType, hashTable);
elementType retrieve(position, hashTable);
hashTable rehash(hashTable);

#endif
