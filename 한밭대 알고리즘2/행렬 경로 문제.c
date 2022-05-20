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
	(*cnt)++; //함수가 호출(재귀) 될 때마다 카운트
	if (i == 0 && j == 0) { //첫 번째 행렬일 때 첫번째 행렬을 반환한다.
		
		return arr[i][j]; 
	}
	else if (i == 0) { //1열 일때만 들어와서
		
		return loop(arr, cnt, i, j - 1)+arr[i][j]; //1열의 각 행값들을 반환
	}
	else if (j == 0) { //1행 일때만 들어와서
		
		return loop(arr, cnt, i-1, j) + arr[i][j]; //1행의 값 열값들을 반환
	}else{
		return max_path(loop(arr, cnt, i, j - 1) + arr[i][j], loop(arr, cnt, i - 1, j) + arr[i][j]);
		//그게 아니라면 현재값 + 이전 행값 혹은 이전 열값을 더한 값 중 더 큰 값을 반환한다.
	}
	//그러면 마지막에는 최고점이 반환된다.
}
int dp(int** arr, int** c,int n, int* cnt2) {
	c[0][0] = arr[0][0]; //행렬의 첫 번째 테이블에 첫 번째 값을 담는다
	(*cnt2)++; 

	for (int i = 1; i < n; i++) {
		c[0][i] = arr[0][i] + c[0][i - 1]; //1열일 때 행들의 누적 값들을 각 테이블에 담는다

		(*cnt2)++;
	}
	for (int i = 1; i < n; i++) {
		c[i][0] = arr[i][0] + c[i - 1][0]; //1행일 때 열들의 누적 값들을 각 테이블에 담는다 
		(*cnt2)++;
	}
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			
			c[i][j]=max_path(arr[i][j] + c[i - 1][j], arr[i][j] + c[i][j - 1]); //기억 되어있는 누적값들을 이용하여
			//현재값과 더한 -1열 이나 -1행 중에서 더 큰 값을 현재 테이블에 담는다
			
			(*cnt2)++;
		}
	}
	return c[n-1][n-1]; //최고점 반환
}
int main() {
	int n, cnt1 = 0, cnt2 = 0; 
	scanf("%d", &n); //행렬의 크기 n * n

	int** arr = (int**)malloc(sizeof(int*) * n); //행렬을 크기만큼 선언

	for (int i = 0; i < n; i++) {
		arr[i] = (int*)malloc(sizeof(int) * n); 
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &arr[i][j]);  //행렬에 값을 입력
		}
	}
	
	int** c = (int**)malloc(sizeof(int*) * n); //행렬의 테이블이 되어줄 행렬을 선언

	for (int i = 0; i < n; i++) {
		c[i] = (int*)malloc(sizeof(int) * n);
	}

	printf("재귀함수 최고점:%d\n동적프로그래밍 최고점:%d\n\n", 
		loop(arr, &cnt1, n - 1, n - 1), dp(arr, c, n, &cnt2)); //재귀함수일 떄,동적 프로그래밍일 때 각각 호출
	printf("재귀함수 때 수행횟수:%d\n동적프로그래밍 때 수행횟수:%d", cnt1+1, cnt2);
	
}