#include <stdio.h>

int main()
{
	int x = 4;  // 변수 x 선언 및 4로 초기화
	int y = 2;  // 변수 y 선언 및 2로 초기화
	int z;  // 변수 z 선언

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