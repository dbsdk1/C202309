#include <stdio.h>
#define STUDENTS 5  // 컴파일 될 때 상수값 정의됨

void classifyStudents(int scores[], char targetGrade) {
	printf("학생 성적 분류:\n");
	char grade = "";
	for (int i = 0; i < STUDENTS; i++) {  // i가 0부터 시작하고 한번 돌고나면 1씩 증가, i가 5보다 작을때까지 반복
		if (scores[i] >= 90) {  // 배열, 만약 i에 0 들어감 -> 배열의 크기는 0이다.
			grade = 'A';  // 만약 scores[i]가 90보다 크거나 작으면 성적은 A이다.
		}
		else if (scores[i] >= 80) {
			grade = 'B';
		}
		else if (scores[i] >= 70) {
			grade = 'C';
		}
		else if (scores[i] >= 60) {
			grade = 'D';
		}
		else {
			grade = 'F';
		}
		if (targetGrade == grade) {
			printf("%d 학생은 %c 점수를 받았습니다.\n", i + 1, targetGrade);  // targetGrade와 grade가 같으면 출력, %d에는 i+1의 값이 넣어지고 %c에는 targetGrade 넣어짐.

		}
	}

}


int sumScores(int scores[]) {
	int sum = 0;
	for (int i = 0; i < STUDENTS; i++)
		sum += scores[i];
		
	return 0;
}

double averageScores(int scores[]) {
	int sum = 0;
	int num = 5;
	double average;
	average = (double)sum / (double)num;

}


void printRanks(int scores[]) {
	int ranks = 1;
	for (int i = 0; i < STUDENTS; i++) {
		for (int j = 0; j < STUDENTS; j++) {
			if (scores[i] >= scores[j])
				ranks = ranks + 0;
			else
				ranks = ranks + 1;
		}
		printf("%d 학생의 순위는 %d 입니다.\n", i + 1, ranks);

	}


	
}





int main() {
	int scores[STUDENTS];

	for (int i = 0; i < STUDENTS; i++) {
		printf("학생 %d의 성적을 입력하세요: ", i + 1);  // 학생 1, 2, 3 이렇게 커지며 출력됨.
		scanf_s("%d", &scores[i]);

	}

	char ch = getchar();  // 버퍼 임시 저장 변수, 엔터지우기 위해

	char target;  // char형
	printf("특정 점수 (A,B,C,D,F)를 입력하시오: ");
	scanf_s("%c", &target, 1);  // 사용자로부터 값 입력받음

	classifyStudents(scores, target);

	int sum = sumScores(scores);
	double average = averageScores(scores);
	printf("학생들의 점수의 총 합은 %d이고, 평균 값은 %lf입니다.\n", sum, average);

	printRanks(scores);

	return 0;
}

