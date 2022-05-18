#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int BUCKET_SIZE = 13; 

// ��� ����ü ����
struct node {
    int key; // �ؽ� �Լ��� ���� Ű
    int value; // key �� ������ �ִ� ������
    struct node* next; // ���� ��带 ����Ű�� ������
};
// table ����ü ����
struct table {
    struct node* head; // ���� ���� �տ� �ִ� ����� ������
    int count; // ���Ͽ� ����ִ� ����� ����
};
struct node* createNode(int key, int value) {
    struct node* newNode;
    // �޸� �Ҵ�
    newNode = (struct node*)malloc(sizeof(struct node));
    // ����ڰ� ������ ���� ����
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL; // ������ ���� next�� NULL�� �ʱ�ȭ

    return newNode;
}
int hashFunction(int key) {
    return key % BUCKET_SIZE;
}
void add(struct table* hashTable,int key, int value) {
    // ��� ���Ͽ� �߰����� �ε����� ���
    int hashIndex = hashFunction(key);
    // ���� ��� ����
    struct node* newNode = createNode(key, value);
    // ����� �ε����� ���Ͽ� �ƹ� ��嵵 ���� ���
    if (hashTable[hashIndex].count == 0) {
        hashTable[hashIndex].count = 1;
        hashTable[hashIndex].head = newNode; // head�� ��ü
    }
    // ���Ͽ� �ٸ� ��尡 ���� ��� ��ĭ�� �а� ���� ��尡 �ȴ�(�����δ� �����͸� �ٲ���)
    else {
        
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;

        //�̰� �ڿ������� �����Ͱ� �̾���
        /*
        struct node* curr = hashTable[hashIndex].head;
        while (curr != NULL) {
            curr = curr->next;
        }
        curr = newNode;
        */
    }
}
void display(struct table* hashTable) {
    // �ݺ��� ����
    struct node* curr;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        curr = hashTable[i].head;
        printf("%d : ", i);
        while (curr != NULL)
        {
            
            printf("(key : %d, val : %d)  -> ", curr->key, curr->value);
            curr = curr->next;
            
        }
        printf("\n");
    }
}
int main() {
    // �ؽ����̺� �޸� �Ҵ�
    struct table* hashTable= (struct table*)malloc(BUCKET_SIZE * sizeof(struct table));

    add(hashTable,55, 55);
    add(hashTable,13, 13);
    add(hashTable,42,42 );
    add(hashTable,70,70 );
    add(hashTable,43,43 );
    add(hashTable,44,44 );
    add(hashTable,3,3 );
    add(hashTable,94,94 );
    add(hashTable,47,47 );
    add(hashTable,74,74 );
    add(hashTable,39,39 );
    add(hashTable,86,86 );
    add(hashTable,76,76 );
    add(hashTable,40,40 );
  

    display(hashTable);
}