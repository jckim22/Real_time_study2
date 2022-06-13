#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getParent(int parent[], int x) { //������ �θ� ��������� ã�´�
	if (parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

void unionParent(int parent[], int a, int b) { //������ ��ġ�� �Լ�
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

//���� Ŭ���� ����
class Edge { //���� Ŭ���� ����
public:
	int node[2]; //������ ���� �Ǿ� �ִ� �� ���
	int distance; //����ġ
	Edge(int a, int b, int distance) { //������ �ʱ�ȭ
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	bool operator <(Edge& edge) { //���Ľ� ����ġ�� ���� ���� ����
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
		if (findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) { //������ ù��° ���� �ι�° ��尡 ����Ǿ� �ִٸ�
			sum += v[i].distance; //�� �Ÿ��� �հ迡 ��´�
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1); //������ �����Ѵ�.
		}
	}
	 
	printf("%d", sum);
}