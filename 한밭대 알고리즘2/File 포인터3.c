#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main() {

	FILE* fp1 = fopen("ex1.txt", "r");
	FILE* fp2 = fopen("ex2.txt", "w");

	char buffer[100];
	char* ptr; //strstr�� �޾���� �ϴ� ������

	while (fgets(buffer, 100, fp1) != NULL) { //�� ��

		ptr = strstr(buffer, "abc"); //������ ù abc�� ã�Ƽ� a�� �ּҸ� ptr�� ��� ��

		while (ptr != NULL) { //�� ���� ������ ���� �Ǿ abc�� ã�� ���ߴٸ� �ݺ����� ����

			strncpy(ptr, "000", 3); //ptr�� ��� abc�� 000���� �ٲ�

			ptr = strstr(buffer, "abc"); //�տ��� 000���� �ٲ���� ������ �� ���� abc�� a�� �ּҸ� ptr�� ����
		}
		fputs(buffer, fp2); //000���� �ٲ� ������ ���� ���Ͽ� �־��ش�.

	}

	fclose(fp1);
	fclose(fp2);
}