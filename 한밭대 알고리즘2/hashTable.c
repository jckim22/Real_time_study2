#include "HashTable.h"
int HashFunction(int key, int tableSize) { //key mod tableSize 연산으로 address를 구한다
	return key % tableSize;
}
hashTable* CreateHashTable(int tableSize) {  //새로운 hashTable 생성
	hashTable* HT = (hashTable*)malloc(sizeof(hashTable)); 
	HT->table = (node*)malloc(sizeof(node) * tableSize);
	HT->tableSize = tableSize;

	return HT;
}
void set(hashTable* HT, int key, int value) { //새로운 node들을 table에 세팅 해준다
	int address = HashFunction(key, HT->tableSize); 
	HT->table[address].key = key;
	HT->table[address].Value = value;
}
int get(hashTable* HT, int key) { //세팅된 테이블에서 노드를 가져온다
	int address = HashFunction(key, HT->tableSize);
	return HT->table[address].Value;
}
void DestroyHashTable(hashTable* HT) {  //malloc으로 받아온 데이터들을 free해준다
	free(HT->table);
	free(HT);
	
}


int main() {
	hashTable* HT = CreateHashTable(193); //193 Size의 hashTable 생성

	set(HT, 23, 3244);  //각각의 값을 넣어주고
	set(HT, 41, 23535);
	set(HT, 9, 1312);
	set(HT, 31, 5632);
	set(HT, 53, 27085);

	//여기까지 적재율은 5/193이다

	printf("Key:%d, Value:%d\n", 23, get(HT, 23)); //값을 가져온다
	printf("Key:%d, Value:%d\n", 41, get(HT, 41));
	printf("Key:%d, Value:%d\n", 9, get(HT, 9));
	printf("Key:%d, Value:%d\n", 31, get(HT, 31));
	printf("Key:%d, Value:%d\n", 53, get(HT, 53));

	DestroyHashTable(HT); //마지막으로 free 시켜준다


	return 0;
}