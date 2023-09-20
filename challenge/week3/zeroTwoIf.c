#include <stdio.h>

int main() {
	int num = 0;  // 변수 선언 및 초기화
	printf("숫자를 입력하시오: ");  // 시작하면 숫자를 입력하라고 띄움
	scanf_s("%d", &num);  // 사용자로부터 값 입력받기
	if (num == 0) {
		printf("zero");  // 0을 입력할 경우 zero를 출력
	}
	else if (num == 1) {
		printf("one");  // 1을 입력할 경우 one을 출력
	}
	else if (num == 2) {
		printf("two");  // 2를 입력할 경우 two를 출력
	}
	else
		printf("not 0~2");  // 0, 1, 2 모두 아닐 경우 출력되는 메세지

	return 0;
}