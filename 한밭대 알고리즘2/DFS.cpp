#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int c[7];
vector<int> a[8];

void dfs(int x) {
	if (c[x]) return;
	c[x] = true; //방문 처리 해주고
	cout << x << ' ';
	for (int i = 0; i < a[x].size(); i++) {// 인접노드 방문
		int y = a[x][i];
		dfs(y); //인접 노드를 계속해서 dfs 수행
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

	dfs(1); //시작점

}