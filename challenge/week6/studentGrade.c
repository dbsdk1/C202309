#include <stdio.h>
#define STUDENTS 5  // ������ �� �� ����� ���ǵ�

void classifyStudents(int scores[], char targetGrade) {
	printf("�л� ���� �з�:\n");
	char grade = "";
	for (int i = 0; i < STUDENTS; i++) {  // i�� 0���� �����ϰ� �ѹ� ������ 1�� ����, i�� 5���� ���������� �ݺ�
		if (scores[i] >= 90) {  // �迭, ���� i�� 0 �� -> �迭�� ũ��� 0�̴�.
			grade = 'A';  // ���� scores[i]�� 90���� ũ�ų� ������ ������ A�̴�.
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
			printf("%d �л��� %c ������ �޾ҽ��ϴ�.\n", i + 1, targetGrade);  // targetGrade�� grade�� ������ ���, %d���� i+1�� ���� �־����� %c���� targetGrade �־���.

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
		printf("%d �л��� ������ %d �Դϴ�.\n", i + 1, ranks);

	}


	
}





int main() {
	int scores[STUDENTS];

	for (int i = 0; i < STUDENTS; i++) {
		printf("�л� %d�� ������ �Է��ϼ���: ", i + 1);  // �л� 1, 2, 3 �̷��� Ŀ���� ��µ�.
		scanf_s("%d", &scores[i]);

	}

	char ch = getchar();  // ���� �ӽ� ���� ����, ��������� ����

	char target;  // char��
	printf("Ư�� ���� (A,B,C,D,F)�� �Է��Ͻÿ�: ");
	scanf_s("%c", &target, 1);  // ����ڷκ��� �� �Է¹���

	classifyStudents(scores, target);

	int sum = sumScores(scores);
	double average = averageScores(scores);
	printf("�л����� ������ �� ���� %d�̰�, ��� ���� %lf�Դϴ�.\n", sum, average);

	printRanks(scores);

	return 0;
}

