#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


int BUCKET_SIZE = 13; 

// 노드 구조체 선언
struct node {
    int key; // 해시 함수에 사용될 키
    int value; // key 가 가지고 있는 데이터
    struct node* next; // 다음 노드를 가르키는 포인터
};
// table 구조체 선언
struct table {
    struct node* head; // 버켓 가장 앞에 있는 노드의 포인터
    int count; // 버켓에 들어있는 노드의 개수
};
struct node* createNode(int key, int value) {
    struct node* newNode;
    // 메모리 할당
    newNode = (struct node*)malloc(sizeof(struct node));
    // 사용자가 전해준 값을 대입
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL; // 생성할 때는 next를 NULL로 초기화

    return newNode;
}
int hashFunction(int key) {
    return key % BUCKET_SIZE;
}
void add(struct table* hashTable,int key, int value) {
    // 어느 버켓에 추가할지 인덱스를 계산
    int hashIndex = hashFunction(key);
    // 새로 노드 생성
    struct node* newNode = createNode(key, value);
    // 계산한 인덱스의 버켓에 아무 노드도 없을 경우
    if (hashTable[hashIndex].count == 0) {
        hashTable[hashIndex].count = 1;
        hashTable[hashIndex].head = newNode; // head를 교체
    }
    // 버켓에 다른 노드가 있을 경우 한칸씩 밀고 내가 헤드가 된다(실제로는 포인터만 바꿔줌)
    else {
        
        newNode->next = hashTable[hashIndex].head;
        hashTable[hashIndex].head = newNode;
        hashTable[hashIndex].count++;

        //이건 뒤에서부터 데이터가 이어짐
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
    // 반복자 선언
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
    // 해시테이블 메모리 할당
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