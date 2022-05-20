#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int max_path(int a,int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int loop(int** arr,int* cnt, int i, int j) {
	(*cnt)++; //�Լ��� ȣ��(���) �� ������ ī��Ʈ
	if (i == 0 && j == 0) { //ù ��° ����� �� ù��° ����� ��ȯ�Ѵ�.
		
		return arr[i][j]; 
	}
	else if (i == 0) { //1�� �϶��� ���ͼ�
		
		return loop(arr, cnt, i, j - 1)+arr[i][j]; //1���� �� �ప���� ��ȯ
	}
	else if (j == 0) { //1�� �϶��� ���ͼ�
		
		return loop(arr, cnt, i-1, j) + arr[i][j]; //1���� �� �������� ��ȯ
	}else{
		return max_path(loop(arr, cnt, i, j - 1) + arr[i][j], loop(arr, cnt, i - 1, j) + arr[i][j]);
		//�װ� �ƴ϶�� ���簪 + ���� �ప Ȥ�� ���� ������ ���� �� �� �� ū ���� ��ȯ�Ѵ�.
	}
	//�׷��� ���������� �ְ����� ��ȯ�ȴ�.
}
int dp(int** arr, int** c,int n, int* cnt2) {
	c[0][0] = arr[0][0]; //����� ù ��° ���̺� ù ��° ���� ��´�
	(*cnt2)++; 

	for (int i = 1; i < n; i++) {
		c[0][i] = arr[0][i] + c[0][i - 1]; //1���� �� ����� ���� ������ �� ���̺� ��´�

		(*cnt2)++;
	}
	for (int i = 1; i < n; i++) {
		c[i][0] = arr[i][0] + c[i - 1][0]; //1���� �� ������ ���� ������ �� ���̺� ��´� 
		(*cnt2)++;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			
			c[i][j]=max_path(arr[i][j] + c[i - 1][j], arr[i][j] + c[i][j - 1]); //��� �Ǿ��ִ� ���������� �̿��Ͽ�
			//���簪�� ���� -1�� �̳� -1�� �߿��� �� ū ���� ���� ���̺� ��´�
			
			(*cnt2)++;
		}
	}
	return c[n-1][n-1]; //�ְ��� ��ȯ
}
int main() {
	int n, cnt1 = 0, cnt2 = 0; 
	scanf("%d", &n); //����� ũ�� n * n

	int** arr = (int**)malloc(sizeof(int*) * n); //����� ũ�⸸ŭ ����

	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n); 
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);  //��Ŀ� ���� �Է�
		}
	}
	
	int** c = (int**)malloc(sizeof(int*) * n); //����� ���̺��� �Ǿ��� ����� ����

	for (int i = 0; i < n; i++) {
		c[i] = (int*)malloc(sizeof(int) * n);
	}

	printf("����Լ� �ְ���:%d\n�������α׷��� �ְ���:%d\n\n", 
		loop(arr, &cnt1, n - 1, n - 1), dp(arr, c, n, &cnt2)); //����Լ��� ��,���� ���α׷����� �� ���� ȣ��
	printf("����Լ� �� ����Ƚ��:%d\n�������α׷��� �� ����Ƚ��:%d", cnt1+1, cnt2);
	
}