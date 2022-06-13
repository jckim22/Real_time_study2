#include <iostream>

using namespace std;

int getParent(int parent[], int x) { //원래의 부모를 재귀적으로 찾는다
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

int unionParent(int parent[], int a, int b) { //집합을 합치는 함수
	a = getParent(parent, a); //부모를 찾아온다.
	b = getParent(parent, b); //부모를 찾아온다 
	if (a < b)parent[b] = a; //더 작은 값을 부모로 갖게 한다
	else parent[a] = b; 
}

int findParent(int parent[], int a, int b) { //부모가 같으면 연결 되어 있으므로 1을 반환한다.
	a = getParent(parent, a); 
	b = getParent(parent, b);
	if (a == b) return 1;
	return 0;
}

int main() {
	int parent[11];
	for (int i = 1; i <= 10; i++) {
		parent[i] = i; //자기 자신을 부모로 갖는다
	}
	unionParent(parent,1 ,2);
	unionParent(parent,2 ,3);
	unionParent(parent,3 ,4);
	unionParent(parent,5, 2);
	unionParent(parent,1 ,2);
	unionParent(parent,1 ,2);

	printf("연결 확인(5,2) : %d", findParent(parent, 5, 2));
}