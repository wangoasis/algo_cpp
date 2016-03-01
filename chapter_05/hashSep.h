typedef int elementType;

#ifndef _HASHSEP_H
#define _HASHSEP_H

struct listNode;
typedef struct listNode *position;
struct hashTbl;
typedef struct hashTbl *hashTable;

hashTable init(int);
void destroyTable(hashTable);
position find(elementType, hashTable);
void insert(elementType, hashTable);
elementType retrieve(position);
void delete(elementType, hashTable);

#endif
