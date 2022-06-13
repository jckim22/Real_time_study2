#include <iostream>

using namespace std;

int getParent(int parent[], int x) { //������ �θ� ��������� ã�´�
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

int unionParent(int parent[], int a, int b) { //������ ��ġ�� �Լ�
	a = getParent(parent, a); //�θ� ã�ƿ´�.
	b = getParent(parent, b); //�θ� ã�ƿ´� 
	if (a < b)parent[b] = a; //�� ���� ���� �θ�� ���� �Ѵ�
	else parent[a] = b; 
}

int findParent(int parent[], int a, int b) { //�θ� ������ ���� �Ǿ� �����Ƿ� 1�� ��ȯ�Ѵ�.
	a = getParent(parent, a); 
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}

int main() {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i; //�ڱ� �ڽ��� �θ�� ���´�
	}
	unionParent(parent,1 ,2);
	unionParent(parent,2 ,3);
	unionParent(parent,3 ,4);
	unionParent(parent,5, 2);
	unionParent(parent,1 ,2);
	unionParent(parent,1 ,2);

	printf("���� Ȯ��(5,2) : %d", findParent(parent, 5, 2));
}