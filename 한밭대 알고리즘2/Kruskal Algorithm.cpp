#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int parent[], int x) { //원래의 부모를 재귀적으로 찾는다
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) { //집합을 합치는 함수
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

//간선 클래스 선언
class Edge { //간선 클래스 선언
public:
	int node[2]; //간선에 연결 되어 있는 두 노드
	int distance; //가중치
	Edge(int a, int b, int distance) { //생성자 초기화
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) { //정렬시 가중치가 작은 것을 기준
		return this->distance < edge.distance;
	}

};


int main() {
	int n = 7;
	int m = 11;
	int sum = 0;

	vector<Edge> v;
	v.push_back(Edge(1, 7, 12));
	v.push_back(Edge(1, 4, 28));
	v.push_back(Edge(1, 2, 67));
	v.push_back(Edge(1, 5, 17));
	v.push_back(Edge(2, 4, 24));
	v.push_back(Edge(2, 5, 62));
	v.push_back(Edge(3, 5, 20));
	v.push_back(Edge(3, 6, 37));
	v.push_back(Edge(4, 7, 13));
	v.push_back(Edge(5, 6, 45));
	v.push_back(Edge(5, 7, 73));

	sort(v.begin(), v.end());

	int parent[7];

	for (int i = 0; i < v.size(); i++) {
		if (findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) { //간선의 첫번째 노드와 두번째 노드가 연결되어 있다면
			sum += v[i].distance; //그 거리를 합계에 담는다
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1); //집합을 연결한다.
		}
	}
	 
	printf("%d", sum);
}