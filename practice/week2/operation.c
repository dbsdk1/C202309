#include <stdio.h>

int main()
{
	int x = 4;  // ���� x ���� �� 4�� �ʱ�ȭ
	int y = 2;  // ���� y ���� �� 2�� �ʱ�ȭ
	int z;  // ���� z ����

	z = x + y;
	printf("z = x + y = %d\n", z);
	z = x - y;
	printf("z = x - y = %d\n", z);
	z = x * y;
	printf("z = x * y = %d\n", z);
	z = x / y;
	printf("z = x / y = %d\n", z);

	return 0;
}