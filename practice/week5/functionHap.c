#include <stdio.h>

int hapf(int value);  //함수 원형 선언

void main()  //호출자
{
	printf("1부터     10까지의 합은 %d\n", hapf(10));
	printf("1부터    100까지의 합은 %d\n", hapf(100));
	printf("1부터  1000까지의 합은 %d\n", hapf(1000));  // hapf함수 호출해서 반환값을 출력한다.
}

int hapf(int value)  //피호출자, 함수명은 hapf이다.
{
	int i;
	int hap = 0;  // 변수 선언 및 초기화

	i = 1;
	while (i <= value) {  // i<=value 일때까지 반복
		hap = hap + i;
		i = i + 1;  // i가 1, 2, 3... 1씩 더해진게 i가 된다.
	}
	return hap;  // int형으로 hap(결과값) 반환
}
