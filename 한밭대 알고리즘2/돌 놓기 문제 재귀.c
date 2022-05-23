#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

int check(int p, int q) {
	int checkP = 0;
	if (p == 0) {
		if (q == 1 || q == 2) { //패턴이 0일때 1,2패턴만 양립
			checkP = 1;
		}
	}
	else if (p == 1) { //패턴이 1일 때 0,2,3, 패턴만 양립
		if (q != 1) {
			checkP = 1;
		}
	}
	else if (p == 2) { //패턴이 2일 때 패턴 0,1만 양립 가능
		if (q == 0 || q == 1) {
			checkP = 1;
		}
	}
	else if (p == 3) { //패턴 3일 때 1패턴만 양립 가능
		if (q == 1) {
			checkP = 1;
		}
	}

	return checkP; //가능 여부를 리턴
}
int pebble(int** w,int i, int p) {
	int tmp;
	
	if (i = 0) {
		return w[i][p]; //재귀의 끝, 열이 한개라면 그 열의 알맞은 패턴을 반환
	}
	else {
		int max = 0;
		for (int q = 0; q < 4; q++) {
			if (check(p, q)) { //p와 현재 보려는 패턴 q가 양립한다면
				tmp = pebble(w,i - 1, q); 
				if (tmp > max) {
					max = tmp; //max 값을 구해준다
				}
			}
		}
		return max + w[i][p]; //그리고 n-1번째까지 max와 현재 열에 알맞은 패턴을 더해서 리턴한다.
	}
}
int pebbleLoop(int** w, int n) {
	int tmp;
	int max = 0;
	for (int i = 0; i < 4; i++) {//0-3 패턴을 한번씩 재귀하고 가장 큰 값을 max에 담음
		tmp=pebble(w, n);
		if (tmp > max) {
			max = tmp;
			
		}
	}
	return max; 
}

int main() {
	int n;

	scanf("%d", &n); //열의 크기를 입력 받음

	int** arr = (int**)malloc(sizeof(int*) * 3); //조약돌 배열 할당

	for (int i = 0; i < 3; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);  //크기만큼 숫자 입력
		}
	}
	printf("\n--------테이블---------\n");
	for (int i = 0; i < 3; i++) {
		printf("\n");
		for (int j = 0; j < n; j++) {
			printf("%d ", arr[i][j]);  //테이블 출력
			if (arr[i][j] < 10) {
				printf(" ");
			}
		}
	}

	printf("재귀함수 시 최대값:%d\n", pebbleLoop(arr, n - 1);
}