#include <stdio.h>

int main() {
	int floor;  // 변수 선언 및 초기화
	printf("몇 층으로 쌓겠습니까? (5~100)");
	scanf_s("%d", &floor);  // 층 입력받고 floor에 저장

	for (int i = 0; i < floor; i++) // 반복문for 사용 i가 floor보다 작을때까지 반복, i에 1씩 더해나감.
	{
		// 이중반복문
		for (int j = 0; j < floor - 1-i ; j++) {  // 4,3,2,1,0 처럼 줄어든다. j가 floor-1-i보다 작을때까지 반복, j에는 1씩 더해나감.
			printf("S");
		}
		for (int k = 0; k < i * 2 + 1; k++) {
			printf("*");  // 별 개수가 1,3,5,7,9 (i*2+1)만큼 출력됨.

		}
		printf("\n"); // 줄바꿔서 피라미드 모양이 나오게 한다.


	}



	return 0;
}