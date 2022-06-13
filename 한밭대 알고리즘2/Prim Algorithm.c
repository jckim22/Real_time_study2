#include <stdio.h>
#include <stdlib.h>

//간선 구조체 선언
typedef struct Edge {

	int node[2]; //간선에 연결 되어 있는 두 노드
	int distance; //가중치
	struct Edge(int a, int b, int distance) { //생성자 초기화
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

}Edge;

Edge* Init_Edge(int max_vertex); // 이중 포인터를 사용하여 간선의 가중치를 저장하는 Edge 구조체의 이중 포인터 key를 초기화 합니다. 

void Init_Graph(Edge* e, int n); // n을 최대값으로 갖는 랜덤 변수를 생성하고, 간선 정보를 생성한다.
void Insert_Edge(Edge* e, int v1, int v2, int weight); // 랜덤으로 생성된 간선 정보를 Edge 구조체 포인터에 저장한다.



int Check_Weight(Edge* e, int v1, int v2); // v1과 v2를 잇는 간선의 가중치를 반환한다.

void Prim(Edge* e, int start_vertex); // Prim 알고리즘을 실행한다.

// 이건 처음 공부할 때 봤던 강노에서 제시한 큐를 사용한 Prim 알고리즘을 구현한 것입니다.

/*---------------------------*/

void Add_Queue(int n); // Prim 알고리즘을 사용하기 위한 큐 입력 함수

int Delete_Queue(void); // Prim 알고리즘을 사용하기 위한 큐 삭제(반환) 함수

/*---------------------------*/



/*-------Lecture Note-------*/

// 다른 강의 노트에 있는 큐를 사용하지 않는  Prim 알고리즘

int selected[MAX_VERTEX];

int dist[MAX_VERTEX];



int get_min_vertex(int n);

void prim(Edge* e, int s, int n);

/*--------------------------*/
int get_min_vertex(int n) {
	// 그래프에 포함되지 않은 정점 중에서 가중치가 가장 작은 정점을 반환한다.
	int v, i;
	v = -1;

	for (i = 0; i < n; i++)
		if (!selected[i]) { // 그래프에 포함되지 않은 정점을 찾을 때까지 반복합니다.
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (dist[i] < dist[v]))
			// 앞서 찾은 정점을 시작으로 그래프에 포함되지 않은 정점 전부를 검사하며 가중치가 가장 작은 정점을 찾습니다.
			v = i;
	return v;
}
void prim(Edge* e, int s, int n) {
	// s는 시작 정점, n은 전체 정점의 수
	int i, u, v;

	for (u = 0; u < n; u++) {
		dist[u] = INF;
		selected[u] = 0;
	}

	dist[s] = 0;

	for (i = 0; i < n; i++) {

		u = get_min_vertex(n); // 위의 함수를 이해하시면 아시겠지만, 무조건 처음엔 정점 0이 반환됩니다.
		selected[u] = 1;  // 위에서 그래프에 포함되지 않고 가중치가 가장 적은 정점이 반환됐으므로, 그래프에 포함됐다고 갱신해준다.

							  // 예외는 해당 정점의 dist가 INF 일 경우입니다.

		if (dist[u] == INF) // 가중치가 가장 낮은 정점이 반환됐을텐데, 정점의 dist가 INF이면 알고리즘을 중지합니다. 

			return;

		printf("%2d  ", u);

		for (v = 0; v < n; v++)
			if (e->key[u][v] != INF) // 앞서 반환된 정점(u)과 연결되어 있고 (INF는 끊긴거니까)
				if (!selected[v] && e->key[u][v] < dist[v]) {
				// 이전에 반환됐던 정점이 아니고, 원래 dist 보다 앞서 반환된 정점(u)을 거쳐서 가는 경로의 가중치가 낮다면
					dist[v] = e->key[u][v]; // 앞서 반환된 정점(u)을 거쳐서 가는 경로의 가중치로 갱신한다.
//                    printf("[u -- v] == [%d -- %d] == dist[%d]\n", u, v, dist[v]);
				}

		// 해당 for 문을 앞서 반환된 정점(u)를 기준으로 그래프의 모든 정점에 대해 진행한다.
		// 자연스럽게 끊긴 애들은 무한대가 유지되어 위에 if문으로 제외된다. 

	}
	printf("\n\nShow each weight from start vertex to the others\n");

	// 갱신된 dist 결과를 출력합니다.

	for (i = 0; i < n; i++) {
		printf("dist[%d] = %d\n", i, dist[i]);
	}
	printf("\n\n");
}

Edge* Init_Edge(int max_vertex) {// MAX_VERTEX*MAX_VERTEX 크기의 key 행렬 생성

	Edge* e;

	e = (Edge*)malloc(sizeof(Edge));
	e->n = 0;
	e->key = (int**)malloc(sizeof(int*) * max_vertex);

	for (int i = 0; i < max_vertex; i++) {

		// 이중 포인터를 이중 배열로 사용하기 위해 메모리를 할당한다.

		// 즉, 10x10 배열을 사용할 때, 10개의 행을 만들어주는 것과 같다.
		e->key[i] = (int*)malloc(sizeof(int) * max_vertex);
		// 여기선 각 행 마다 10개의 열을 만들어주는 것과 같다.
		memset(e->key[i], 0, sizeof(int) * max_vertex);
		// 할당된 메모리를 NULL로 초기화 해준다.
	}
	return e;

}

void Init_Graph(Edge* e, int n) {

	//    srand((unsigned int)time(NULL));

	srand((unsigned int)10);

	int ran_num;

	for (int i = 0; i < MAX_VERTEX; i++) {
		for (int j = i; j < MAX_VERTEX; j++) {
			if (j != i) {
				// i, j를 잇는 간선 정보를 생성한다.
				// i->j 가 한번 생기고, j->i가 또 한번 생기는데
				// 결국 후자로 초기화된다
				ran_num = (rand() % n) + 1;
				printf("[%d] and [%d]: %d\n", i, j, ran_num);

				Insert_Edge(e, i, j, ran_num);

			}
			else {
				// 같은 정점에 대한 간선은 없으므로, 가중치를 0으로 설정한다.

				printf("[%d] and [%d]: %d\n", i, j, 0);
				Insert_Edge(e, i, j, 0);
			}
		}
		printf("Finish [%d]\n\n", i);

	}
	printf("\nInit graph complete\n\n");
}

void Insert_Edge(Edge* e, int v1, int v2, int weight) {

	// 랜덤하게 생성된 가중치를 이용해, v1과 v2를 잇는 간선 정보를 설정한다.
	e->key[v1][v2] = weight;
	e->key[v2][v1] = weight;
}

