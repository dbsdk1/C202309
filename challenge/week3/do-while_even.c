#include <stdio.h>

int main()
{
	int i = 0;  // 변수 선언 및 초기화
	do {
		i++;
		if (i % 2 == 0) {
			continue;  // 짝수면은 계속해서 다음거로 넘어가서 계속 진행
		}
		printf("%d Hello World!\n", i);
	} while (i < 10);  // 반복문(i가 10 미만일때까지)

}