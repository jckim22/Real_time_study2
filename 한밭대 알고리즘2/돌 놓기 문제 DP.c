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
int pebbleDP(int** w, int** peb,int n) {
	int tmp,max=0;
	

	for (int p = 0; p < 4; p++) {
		peb[0][p] = w[0][p]; //맨 첫번째 열에 값을 담는다
	}
	for (int i = 1; i < n; i++) { //열
		for (int p = 0; p < 4; p++) { //그 열에 각각의 패턴
			for (int q = 0; q < 4; q++) { //그 패턴과 양립하는 패턴
				if (check(p, q)) {  //양립가능하다면 max값을 담는다
					tmp = peb[i - 1][q] + w[i][p]; 
					if (tmp > max) {
						max = tmp;
					}
				}

			}
			peb[i][p] = max; //마지막에 max값을 테이블에 담아준다
		}
	}

	max = peb[n - 1][0]; //max를 첫번째 요소로 초기화 해주고

	for (int i = 1; i < 4; i++) { //0~3패턴 중 맥스값을 찾아서
		if (peb[n - 1][i] > max) {
			max = peb[n - 1][i];
		}
	}
	return max; //리턴
	
}
int main() {
	int n;

	scanf("%d", &n); //열의 크기를 입력 받음

	int** arr = (int**)malloc(sizeof(int*) * 3); //조약돌 배열 할당

	for (int i = 0; i < 3; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n);
	}

	int** peb = (int**)malloc(sizeof(int*) * 3); //테이블 배열 할당

	for (int i = 0; i < 3; i++) {
		peb[i] = (int*)malloc(sizeof(int) * n);
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

	printf("%d", pebbleDP(arr, peb, n));

}