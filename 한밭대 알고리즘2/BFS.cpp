#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int number = 7;
int c[7]; //방문 체크 배열
vector<int> a[8]; //1-7의 인덱스

void bfs(int start) {
	queue<int> q; //큐를 생성
	q.push(start); //큐에 시작 정점을 담는다
	c[start] = true; //시작 정점을 방문 처리한다.
	while (!q.empty()) { //큐가 공집합 일 때 까지 반복
		int x = q.front(); //q에 첫번째 값을 x에 담고
		q.pop(); //큐에서 지운다
		printf("%d ", x); 
		for (int i = 0; i < a[x].size(); i++) { //큐에서 꺼낸 노드의 모든 인접한 노드 수 만큼 반복
			int y = a[x][i]; //인접한 노드를 y에 담고
			if (!c[y]) { //방문하지 않았다면
				q.push(y); //큐에 넣어주고
				c[y] = true; //방문 처리한다.
			}
		}
	}
}

int main() {
	a[1].push_back(2); //1과 2를 연결
	a[2].push_back(1);


	a[1].push_back(3); //1과 3을 연결
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

	bfs(1); //시작점

}