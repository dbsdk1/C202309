#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // 할 일 목록을 저장하기 위한 2차원 배열
int taskCount = 0; // 할 일 개수 저장하는 변수


void addTask(char task[]) {// 함수 선언
	printf("할 일을 입력하세요 (공백 없이 입력하세요): ");
	scanf_s("%s", task, (int)sizeof(task));
	strcpy_s(tasks[taskCount], sizeof(tasks[taskCount]), task);  // task[taskCount]에 할 일 저장(taskCount는 0부터 들어감), 사이즈도 써주기
	printf("할 일 ""%s""가 저장되었습니다\n\n", task);  // task[taskCount]에 저장된 문자열 출력
}

void delTask(int delIndex, int taskCount) {

	printf("%d. %s : 할 일을 삭제합니다.\n", delIndex, tasks[delIndex - 1]);  // delIndex에서 1을 빼야 할 일의 인덱스와 같아진다!

	// 입력한 번호의 할 일 삭제 후 뒤에 있는 할 일을 앞으로 옮김.
	for (int i = delIndex; i < taskCount + 1; i++) {
		strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
	}
}

void printTask(int taskCount) {
	for (int i = 0; i < taskCount; i++) {  // for 반복문 i가 taskCount보다 작을 때까지 반복
		printf("%d. %s \n", i + 1, tasks[i]);  // i가 0부터였기 때문에 출력할 때 1부터 출력되도록 %d에 들어갈 것은 1을 더했다. %s에는 tasks[i] 문자열이 들어가서 출력된다.
	}
	printf("\n");
}

int main() {
	printf("TODO 리스트 시작! \n");

	while (1) {
		int choice = -1; // 사용자 입력 메뉴를 저장하기 위한 변수

		// 시작하면 쫙 프린트 되고 scanf_s로 번호를 입력받게 한다.
		printf("------------------\n");
		printf("메뉴를 입력해주세요.\n");
		printf("1. 할 일 추가\n2. 할 일 삭제\n3. 목록 보기\n4. 종료\n5.할 일 수정\n");
		printf("현재 할 일 수 = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // 프로그램 종료를 위한 변수
		int delIndex = -1;  // 할 일 삭제 인덱스 번호 저장 변수

		int changeIndex = -1; // 할 일 수정 인덱스 번호 저장 변수
		char ch; // 버퍼 변수

		// 스위치문
		switch (choice) {
		case 1:
			addTask(tasks[taskCount]);  // 함수 호출
			taskCount++;  // 할 일 개수가 늘어남.
			break;
		case 2:// 할 일 삭제하는 코드 블록 
			printf("삭제할 할 일의 번호를 입력해주세요. (1부터 시작):");
			scanf_s("%d", &delIndex);  // 사용자가 입력한 값을 delIndex에 저장
			if (delIndex > taskCount || delIndex <= 0) {  // 만약 지울 인덱스번호가 할 일 수보다 많거나 0이랑 같거나 작으면(즉, 벗어난 경우)
				printf("삭제 범위가 벗어났습니다.\n");
			}
			else {
				delTask(delIndex, taskCount);  // 함수 호출
				taskCount -= 1;  // 할 일 개수 빼줌
			}
			break;
		case 3:
			printf("할 일 목록\n");
			printTask(taskCount);  // 함수 호출
			break;
		case 4:  // 프로그램 종료
			terminate = 1;
			break;
		case 5:
			printf("수정할 할 일의 번호를 입력하세요.\n");
			scanf_s("%d", &changeIndex);  // 수정할 일 번호 입력받기
			if (changeIndex > taskCount || changeIndex <= 0) {  // changeIndex가 taskCount보다 크거나 0보다 작거나 같으면 
				printf("수정 범위가 벗어났습니다.\n");
				break;
			}
			else {
				strcpy_s(tasks[changeIndex - 1], sizeof(tasks[changeIndex - 1]), "");  // tasks[changeIndex - 1] 지우는 함수

			}
			// 그 자리에 수정할 일 입력받기
			printf("할 일을 입력하세요.\n");
			ch = getchar();  // 버퍼 제거
			scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[changeIndex - 1]));
			break;
		default:  // 1, 2, 3, 4, 5 외의 숫자 입력할 경우 출력
			printf("잘못된 선택입니다. 다시 선택하세요.\n");
		}

		if (terminate == 1) {  // case4에서 terminate가 1이 되는데 이때 종료하게 만드는 if문이다.
			printf("종료를 선택하셨습니다. 프로그램을 종료합니다.\n");
			break;
		}
		if (taskCount == 10) {  // 할 일 개수가 10이 되면 프로그램을 종료하게 만드는 if문
			printf("할 일이 %d개로 다 찼습니다.", taskCount);
			break;
		}
	}
	return 0;
}