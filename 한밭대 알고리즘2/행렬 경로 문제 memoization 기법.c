#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int max_path(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int loop(int** arr,int** c, int* cnt, int i, int j) {

	//�޶��� ���� ��ȯ ���� ���̺� �迭�� ��´ٴ� ���̴�.
	int a, b;
	if (c[i][j]!=-1) {//���̺� �迭�� ���� ����ִٸ�
		return c[i][j]; //�ٷ� �� ��� ��ȯ ī��Ʈ X
	}
	(*cnt)++;
	if (i == 0 && j == 0) {
		
		return c[i][j] = arr[i][j];
	}
	else if (i == 0) {

		return c[i][j]=loop(arr,c, cnt, i, j - 1) + arr[i][j];
	}
	else if (j == 0) {

		return c[i][j]=loop(arr,c, cnt, i - 1, j) + arr[i][j];
	}
	else {
		return c[i][j]= max_path(loop(arr,c, cnt, i, j - 1) + arr[i][j], loop(arr,c, cnt, i - 1, j) + arr[i][j]);

	}
}
int main() {
	int n, cnt = 0;
	scanf("%d", &n);

	int** arr = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}

	int** c = (int**)malloc(sizeof(int*) * n);

	for (int i = 0; i < n; i++) {
		c[i] = (int*)malloc(sizeof(int) * n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			c[i][j] = -1;
		}
	}

	printf("�ְ���:%d\n\nmemoization ����� �� ����Ƚ��:%d ", loop(arr, c, &cnt, n - 1, n - 1),cnt);
}