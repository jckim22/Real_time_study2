#include <stdio.h>
#include <stdlib.h>

//���� ����ü ����
typedef struct Edge {

	int node[2]; //������ ���� �Ǿ� �ִ� �� ���
	int distance; //����ġ
	struct Edge(int a, int b, int distance) { //������ �ʱ�ȭ
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}

}Edge;

Edge* Init_Edge(int max_vertex); // ���� �����͸� ����Ͽ� ������ ����ġ�� �����ϴ� Edge ����ü�� ���� ������ key�� �ʱ�ȭ �մϴ�. 

void Init_Graph(Edge* e, int n); // n�� �ִ밪���� ���� ���� ������ �����ϰ�, ���� ������ �����Ѵ�.
void Insert_Edge(Edge* e, int v1, int v2, int weight); // �������� ������ ���� ������ Edge ����ü �����Ϳ� �����Ѵ�.



int Check_Weight(Edge* e, int v1, int v2); // v1�� v2�� �մ� ������ ����ġ�� ��ȯ�Ѵ�.

void Prim(Edge* e, int start_vertex); // Prim �˰����� �����Ѵ�.

// �̰� ó�� ������ �� �ô� ���뿡�� ������ ť�� ����� Prim �˰����� ������ ���Դϴ�.

/*---------------------------*/

void Add_Queue(int n); // Prim �˰����� ����ϱ� ���� ť �Է� �Լ�

int Delete_Queue(void); // Prim �˰����� ����ϱ� ���� ť ����(��ȯ) �Լ�

/*---------------------------*/



/*-------Lecture Note-------*/

// �ٸ� ���� ��Ʈ�� �ִ� ť�� ������� �ʴ�  Prim �˰���

int selected[MAX_VERTEX];

int dist[MAX_VERTEX];



int get_min_vertex(int n);

void prim(Edge* e, int s, int n);

/*--------------------------*/
int get_min_vertex(int n) {
	// �׷����� ���Ե��� ���� ���� �߿��� ����ġ�� ���� ���� ������ ��ȯ�Ѵ�.
	int v, i;
	v = -1;

	for (i = 0; i < n; i++)
		if (!selected[i]) { // �׷����� ���Ե��� ���� ������ ã�� ������ �ݺ��մϴ�.
			v = i;
			break;
		}
	for (i = 0; i < n; i++)
		if (!selected[i] && (dist[i] < dist[v]))
			// �ռ� ã�� ������ �������� �׷����� ���Ե��� ���� ���� ���θ� �˻��ϸ� ����ġ�� ���� ���� ������ ã���ϴ�.
			v = i;
	return v;
}
void prim(Edge* e, int s, int n) {
	// s�� ���� ����, n�� ��ü ������ ��
	int i, u, v;

	for (u = 0; u < n; u++) {
		dist[u] = INF;
		selected[u] = 0;
	}

	dist[s] = 0;

	for (i = 0; i < n; i++) {

		u = get_min_vertex(n); // ���� �Լ��� �����Ͻø� �ƽð�����, ������ ó���� ���� 0�� ��ȯ�˴ϴ�.
		selected[u] = 1;  // ������ �׷����� ���Ե��� �ʰ� ����ġ�� ���� ���� ������ ��ȯ�����Ƿ�, �׷����� ���Եƴٰ� �������ش�.

							  // ���ܴ� �ش� ������ dist�� INF �� ����Դϴ�.

		if (dist[u] == INF) // ����ġ�� ���� ���� ������ ��ȯ�����ٵ�, ������ dist�� INF�̸� �˰����� �����մϴ�. 

			return;

		printf("%2d  ", u);

		for (v = 0; v < n; v++)
			if (e->key[u][v] != INF) // �ռ� ��ȯ�� ����(u)�� ����Ǿ� �ְ� (INF�� ����Ŵϱ�)
				if (!selected[v] && e->key[u][v] < dist[v]) {
				// ������ ��ȯ�ƴ� ������ �ƴϰ�, ���� dist ���� �ռ� ��ȯ�� ����(u)�� ���ļ� ���� ����� ����ġ�� ���ٸ�
					dist[v] = e->key[u][v]; // �ռ� ��ȯ�� ����(u)�� ���ļ� ���� ����� ����ġ�� �����Ѵ�.
//                    printf("[u -- v] == [%d -- %d] == dist[%d]\n", u, v, dist[v]);
				}

		// �ش� for ���� �ռ� ��ȯ�� ����(u)�� �������� �׷����� ��� ������ ���� �����Ѵ�.
		// �ڿ������� ���� �ֵ��� ���Ѵ밡 �����Ǿ� ���� if������ ���ܵȴ�. 

	}
	printf("\n\nShow each weight from start vertex to the others\n");

	// ���ŵ� dist ����� ����մϴ�.

	for (i = 0; i < n; i++) {
		printf("dist[%d] = %d\n", i, dist[i]);
	}
	printf("\n\n");
}

Edge* Init_Edge(int max_vertex) {// MAX_VERTEX*MAX_VERTEX ũ���� key ��� ����

	Edge* e;

	e = (Edge*)malloc(sizeof(Edge));
	e->n = 0;
	e->key = (int**)malloc(sizeof(int*) * max_vertex);

	for (int i = 0; i < max_vertex; i++) {

		// ���� �����͸� ���� �迭�� ����ϱ� ���� �޸𸮸� �Ҵ��Ѵ�.

		// ��, 10x10 �迭�� ����� ��, 10���� ���� ������ִ� �Ͱ� ����.
		e->key[i] = (int*)malloc(sizeof(int) * max_vertex);
		// ���⼱ �� �� ���� 10���� ���� ������ִ� �Ͱ� ����.
		memset(e->key[i], 0, sizeof(int) * max_vertex);
		// �Ҵ�� �޸𸮸� NULL�� �ʱ�ȭ ���ش�.
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
				// i, j�� �մ� ���� ������ �����Ѵ�.
				// i->j �� �ѹ� �����, j->i�� �� �ѹ� ����µ�
				// �ᱹ ���ڷ� �ʱ�ȭ�ȴ�
				ran_num = (rand() % n) + 1;
				printf("[%d] and [%d]: %d\n", i, j, ran_num);

				Insert_Edge(e, i, j, ran_num);

			}
			else {
				// ���� ������ ���� ������ �����Ƿ�, ����ġ�� 0���� �����Ѵ�.

				printf("[%d] and [%d]: %d\n", i, j, 0);
				Insert_Edge(e, i, j, 0);
			}
		}
		printf("Finish [%d]\n\n", i);

	}
	printf("\nInit graph complete\n\n");
}

void Insert_Edge(Edge* e, int v1, int v2, int weight) {

	// �����ϰ� ������ ����ġ�� �̿���, v1�� v2�� �մ� ���� ������ �����Ѵ�.
	e->key[v1][v2] = weight;
	e->key[v2][v1] = weight;
}

