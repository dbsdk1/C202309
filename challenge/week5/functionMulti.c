#include <stdio.h>

long multiF(long value);  //함수 원형 선언

int main()  //호출자
{
	printf("1부터     2까지의 곱은 %ld\n", multiF(2));
	printf("1부터    3까지의 곱은 %ld\n", multiF(3));
	printf("1부터    5까지의 곱은 %ld\n", multiF(5));  // multiF함수 호출해서 반환값을 출력한다.
	return 0;
}

long multiF(long value)  // 함수명: multiF
{
	long i;
	long multi = 1;

	i = 1;
	while (i <= value) {  // i<=value 일때까지 반복
		multi = multi * i;  // 1x1, 1x2, 2x3 이런식으로 곱해짐.
		i = i + 1;  //i가 1, 2, 3... 1씩 더해짐
	}
	return multi;  // long형으로 결과값 반환
}
