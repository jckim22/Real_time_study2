#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 7;
int c[7]; //�湮 üũ �迭
vector<int> a[8]; //1-7�� �ε���

void bfs(int start) {
	queue<int> q; //ť�� ����
	q.push(start); //ť�� ���� ������ ��´�
	c[start] = true; //���� ������ �湮 ó���Ѵ�.
	while (!q.empty()) { //ť�� ������ �� �� ���� �ݺ�
		int x = q.front(); //q�� ù��° ���� x�� ���
		q.pop(); //ť���� �����
		printf("%d ", x); 
		for (int i = 0; i < a[x].size(); i++) { //ť���� ���� ����� ��� ������ ��� �� ��ŭ �ݺ�
			int y = a[x][i]; //������ ��带 y�� ���
			if (!c[y]) { //�湮���� �ʾҴٸ�
				q.push(y); //ť�� �־��ְ�
				c[y] = true; //�湮 ó���Ѵ�.
			}
		}
	}
}

int main() {
	a[1].push_back(2); //1�� 2�� ����
	a[2].push_back(1);


	a[1].push_back(3); //1�� 3�� ����
	a[3].push_back(1);

	a[2].push_back(3);
	a[3].push_back(2);

	a[2].push_back(4);
	a[4].push_back(2);

	a[2].push_back(5);
	a[5].push_back(2);

	a[3].push_back(6);
	a[6].push_back(3);

	a[3].push_back(7);
	a[7].push_back(3);

	a[4].push_back(5);
	a[5].push_back(4);

	a[6].push_back(7);
	a[7].push_back(6);

	bfs(1); //������

}