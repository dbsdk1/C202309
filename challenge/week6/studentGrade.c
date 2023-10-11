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


int sumScores(int scores[]) {  // sumScores라는 함수이다. 
	int sum = 0;
	for (int i = 0; i < STUDENTS; i++)  // 반복문 i가 STUDENTS(5) 보다 작을때까지 반복, 1씩 더해짐
		sum += scores[i];  // sum = sum + scores[i] -> 점수값을 더해나가는 식
		
	return sum;  // sum 값 반환
}

double averageScores(int scores[]) {
	int sum = sumScores(scores);
	int num = 5;
	double average;  // double형
	average = (double)sum / (double)num;  // 평균구하기, int형을 double형으로 형변환했다. 합에다가 num 나눠서 평균구하기.

	return average;  // average 반환
}


void printRanks(int scores[]) {
// 2중 for문 사용
	for (int i = 0; i < STUDENTS; i++) {  
		int ranks = 1;
		for (int j = 0; j < STUDENTS; j++) {
			if (scores[i] >= scores[j])
				ranks = ranks + 0;  // 만약 scores[i] >= scores[j] 라면 출력됨. 이때는 1등에서 변화가 없어도 되니까 ranks에 0더하기를 했다.
			else
				ranks = ranks + 1;  // scores[i] < scores[j] 일때 출력됨. 1등에 1 더해서 2등으로 내려가는 식으로 순위 하락을 만든다.
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
	printf("학생들의 점수의 총 합은 %d이고, 평균 값은 %lf입니다.\n", sum, average);  // sum, average 집어넣어서 출력됨.

	printRanks(scores);

	return 0;
}

