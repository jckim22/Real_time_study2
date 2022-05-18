#include "HashTable.h"
int HashFunction(int key, int tableSize) { //key mod tableSize �������� address�� ���Ѵ�
	return key % tableSize;
}
hashTable* CreateHashTable(int tableSize) {  //���ο� hashTable ����
	hashTable* HT = (hashTable*)malloc(sizeof(hashTable)); 
	HT->table = (node*)malloc(sizeof(node) * tableSize);
	HT->tableSize = tableSize;

	return HT;
}
void set(hashTable* HT, int key, int value) { //���ο� node���� table�� ���� ���ش�
	int address = HashFunction(key, HT->tableSize); 
	HT->table[address].key = key;
	HT->table[address].Value = value;
}
int get(hashTable* HT, int key) { //���õ� ���̺��� ��带 �����´�
	int address = HashFunction(key, HT->tableSize);
	return HT->table[address].Value;
}
void DestroyHashTable(hashTable* HT) {  //malloc���� �޾ƿ� �����͵��� free���ش�
	free(HT->table);
	free(HT);
	
}


int main() {
	hashTable* HT = CreateHashTable(193); //193 Size�� hashTable ����

	set(HT, 23, 3244);  //������ ���� �־��ְ�
	set(HT, 41, 23535);
	set(HT, 9, 1312);
	set(HT, 31, 5632);
	set(HT, 53, 27085);

	//������� �������� 5/193�̴�

	printf("Key:%d, Value:%d\n", 23, get(HT, 23)); //���� �����´�
	printf("Key:%d, Value:%d\n", 41, get(HT, 41));
	printf("Key:%d, Value:%d\n", 9, get(HT, 9));
	printf("Key:%d, Value:%d\n", 31, get(HT, 31));
	printf("Key:%d, Value:%d\n", 53, get(HT, 53));

	DestroyHashTable(HT); //���������� free �����ش�


	return 0;
}