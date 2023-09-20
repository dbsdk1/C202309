#include <stdio.h>

int main() {
	int choice;  // 변수 선언 및 초기화

	printf("1. 파일 저장\n");
	printf("2. 저장 없이 닫기\n");
	printf("3. 종료\n");
	scanf_s("%d", &choice);  // 사용자로부터 값 입력받아서 choice에 저장

	if (choice == 1)  // 1입력했다면
	{
		printf("파일을 저장합니다.");
	}
	else if (choice == 2) {
		printf("저장 없이 닫습니다.");  // 2입력했다면 이게 출력됨
	}
	else if (choice == 3) {
		printf("종료합니다.");
	}
	else  // 1,2,3이 아닌 다른 수를 입력했을 경우
		printf("잘못 입력하셨습니다.");  

	return 0;
}