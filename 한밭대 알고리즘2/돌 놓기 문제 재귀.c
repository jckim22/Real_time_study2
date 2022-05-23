#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int check(int p, int q) {
	int checkP = 0;
	if (p == 0) {
		if (q == 1 || q == 2) { //������ 0�϶� 1,2���ϸ� �縳
			checkP = 1;
		}
	}
	else if (p == 1) { //������ 1�� �� 0,2,3, ���ϸ� �縳
		if (q != 1) {
			checkP = 1;
		}
	}
	else if (p == 2) { //������ 2�� �� ���� 0,1�� �縳 ����
		if (q == 0 || q == 1) {
			checkP = 1;
		}
	}
	else if (p == 3) { //���� 3�� �� 1���ϸ� �縳 ����
		if (q == 1) {
			checkP = 1;
		}
	}

	return checkP; //���� ���θ� ����
}
int pebble(int** w,int i, int p) {
	int tmp;
	
	if (i = 0) {
		return w[i][p]; //����� ��, ���� �Ѱ���� �� ���� �˸��� ������ ��ȯ
	}
	else {
		int max = 0;
		for (int q = 0; q < 4; q++) {
			if (check(p, q)) { //p�� ���� ������ ���� q�� �縳�Ѵٸ�
				tmp = pebble(w,i - 1, q); 
				if (tmp > max) {
					max = tmp; //max ���� �����ش�
				}
			}
		}
		return max + w[i][p]; //�׸��� n-1��°���� max�� ���� ���� �˸��� ������ ���ؼ� �����Ѵ�.
	}
}
int pebbleLoop(int** w, int n) {
	int tmp;
	int max = 0;
	for (int i = 0; i < 4; i++) {//0-3 ������ �ѹ��� ����ϰ� ���� ū ���� max�� ����
		tmp=pebble(w, n);
		if (tmp > max) {
			max = tmp;
			
		}
	}
	return max; 
}

int main() {
	int n;

	scanf("%d", &n); //���� ũ�⸦ �Է� ����

	int** arr = (int**)malloc(sizeof(int*) * 3); //���൹ �迭 �Ҵ�

	for (int i = 0; i < 3; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);  //ũ�⸸ŭ ���� �Է�
		}
	}
	printf("\n--------���̺�---------\n");
	for (int i = 0; i < 3; i++) {
		printf("\n");
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);  //���̺� ���
			if (arr[i][j] < 10) {
				printf(" ");
			}
		}
	}

	printf("����Լ� �� �ִ밪:%d\n", pebbleLoop(arr, n - 1);
}