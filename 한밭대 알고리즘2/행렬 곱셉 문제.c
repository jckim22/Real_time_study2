#include <stdio.h>
#define Min(A, B) ((A)>(B)?(B):(A))
int matrixChain(int p[], int n);
void Option(int a, int b, int p[]);

int main() {
	int p[6] = { 8,128,64,256,16,8 };
	printf("최솟값 : %d \n", matrixChain(p, 6));
	Option(1, 6, p);
	return 0;
}

int matrixChain(int p[], int n)
{
	int i, j;
	int r, k;
	int m[6][6] = { 0 };
	for (i = 1; i < n; i++)
		m[i][i] = 0;  //행렬이 하나뿐인 경우의 비용은 0이다

	for (r = 1; r < n - 1; r++)  //j의 크기를 결정 여기서 j는 문제의 크기이다
		for (i = 1; i < n - r; i++) { //i의 범위를 설정한다
			j = i + r;
			m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j]; //첫번째 괄호
			for (k = i + 1; k <= j - 1; k++) {
				m[i][j] = Min(m[i][j], m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j]); //이후 모든 괄호를 비교해준다

			}
		}
	return m[1][n - 1]; //최소값을 반환
}

void Option(int a, int b, int p[])
{
	int mul;
	int i;
	int max = p[a];
	int index = 0;
	for (i = a; i < b; i++) {
		if (max < p[i]) {
			max = p[i];
			index = i;
		}
	}
	if (index != a && index != (b - 1)) {
		printf("(A%d X A%d) ", index - 1, index);
		for (i = index; i < b - 1; i++) {
			p[i] = p[i + 1];
		}
		if (b != a)
			Option(a, b - 1, p);
	}
	else
		printf("(A%d X A%d) ", a, b - 1);
}