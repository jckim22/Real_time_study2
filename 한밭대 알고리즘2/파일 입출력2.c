#include <stdio.h>

int main() {
	char buffer[100];

	FILE* fp = fopen("input.txt", "r");
	int cnt = 1;

	printf("���� �̸�:input.txt\n");
	while (fgets(buffer, 100, fp) != NULL) {
		printf("%6d %s\n", cnt, buffer);
		cnt++;
	}
}