#include <stdio.h>

int main()
{
	int i = 0;  // 변수 선언 및 초기화
	
	// 반복문; (i<10) 일때까지 반복
	while (i < 10) {  
		i++;
		if (i % 2 == 0) {
			continue;  // i가 짝수면 넘어가기 
			
		}
		
		printf("%d Hello World!\n", i); // i와 함께 헬로월드 출력
		i++;  // i에 1 더하기
	
		
	}
	return 0;
}