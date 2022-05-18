#ifndef SIMPLE_HASHTABLE_H
#define SIMPLE_HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE { //table의 있는 노드의 구성
	int key;  
	int Value;
}node;

typedef struct HashTable {
	int tableSize;  //node의 수
	node* table;	//진짜 큰 table이고 이곳에 tableSize만큼의 노드를 저장한다.
}hashTable;

hashTable* CreateHashTable(int tableSize);
void set(hashTable* HT, int key, int value);
int get(hashTable* HT, int key);
void DestroyHashTable(hashTable* HT);
int HashFunction(int key, int tableSize);


#endif	SIMPLE_HASHTABLE_H