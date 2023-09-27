#include <stdio.h>

int main() {
	int floor;  // 변수 선언 및 초기화
	printf("몇 층으로 쌓겠습니까? (5~100)");
	scanf_s("%d", &floor);  // 층 입력받고 floor에 저장

	for (int i = floor; i > 0; i--)  // 반복문을 돌때마다 i가 1씩 빼진다.
	{
		
		for (int j = 0; j < floor - i; j++) {  // j가 floor에서 i뺀 값보다 작을때까지 반복, j에 0부터 시작 1씩 더해나가기 
			printf("S");  // floor-i만큼 S출력됨.
		}
		for (int k = 1; k < i * 2; k++) {   
			printf("*");  // 별개수가 ...3,1 순으로 출력된다.

		}
		printf("\n"); // 줄바꿔서 피라미드 모양이 나오게 한다.


	}



	return 0;
}