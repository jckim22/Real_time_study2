#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
int maxSolution(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}
int LCS_loop(char* x, char* y, int m, int n, int* cnt) {
	(*cnt)++;
	if (m == 0 || n == 0) {
		return 0;
	}
	else if (x[m] == y[n]) {
		return LCS_loop(x, y, m - 1, n - 1, cnt) + 1;
	}
	else {
		return maxSolution(LCS_loop(x, y, m - 1, n, cnt), LCS_loop(x, y, m, n - 1, cnt));
	}
}
int LCS(int** table, char* x, char* y, int m, int n, int* cnt) {
	for (int i = 0; i <= m; i++) {
		(*cnt)++;
		table[i][0] = 0; //가장작은 문제들은 0과 문자열을 비교하는 것임으로 LCS는 0이다 그러므로
						 //0으로 채워준다
	}
	for (int j = 0; j <= n; j++) {
		(*cnt)++;
		table[0][j] = 0; //가장작은 문제들은 0과 문자열을 비교하는 것임으로 LCS는 0이다 그러므로
						 //0으로 채워준다
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			(*cnt)++;
			if (x[i] == y[j]) {  //만약 xi 와 yi가 같다면 각자 마지막 문자를 빼고 생각해도
								//되기 때문에 i-1과 j-1을 구하고 한 문자의 길이인 +1을 더한다
				table[i][j] = table[i - 1][j - 1] + 1;

			}
			else { //그게 아니고 다르다면 i-1과 j-1 중에서 max값을 테이블에 저장한다.
				table[i][j] = maxSolution(table[i - 1][j], table[i][j - 1]);

			}
		}
	}
	return table[m][n];

}
int length(char* x) {
	int i;
	for (i = 0; x[i] != NULL; i++) {

	}
	return i;
}
void LCS_print(int** table, char* X, char* Y, int LEN_X, int LEN_Y) {
	int i = 0;
	int j = 0;

	printf("%4s", "");

	for (i = 0; i <= LEN_Y; i++)
		printf("%c ", Y[i]);
	printf("\n");

	for (i = 0; i <= LEN_X; i++)
	{
		if (i == 0)
			printf("%2s", "");
		else
			printf("%-2c", X[i - 1]);

		for (j = 0; j <= LEN_Y; j++)
		{
			printf("%d ", table[i][j]);
		}
		printf("\n");
	}
}


int main() {
	char x[] = "GOOD MORNING.";
	char y[] = "GUTEN MORGEN.";
	int cnt_loop = 0, cnt_DP = 0;

	int LCS_length;
	int len_x = length(x); //x의 길이를 담음
	int len_y = length(y); //y의 길이를 담음

	int** table = (int**)malloc(sizeof(int*) * len_x + 1); //x의 길이만큼 열을 생성

	for (int i = 0; i <= len_x; i++) {
		table[i] = (int*)malloc(sizeof(int) * len_y + 1); //y의 길이만큼 행을 생성
	}

	LCS_length = LCS(table, x, y, len_x, len_y, &cnt_DP);

	LCS_print(table, x, y, len_x, len_y);

	printf("\n동적프로그래밍일 때 LCS: %d", LCS_length);
	printf("\n재귀함수 일때 LCS: %d\n", LCS_loop(x, y, len_x, len_y, &cnt_loop));
	printf("\n동적프로그래밍일 때 수행횟수: %d", cnt_DP);
	printf("\n재귀함수일 때 수행횟수: %d", cnt_loop);

}