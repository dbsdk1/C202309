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


int sumScores(int scores[]) {  // sumScores��� �Լ��̴�. 
	int sum = 0;
	for (int i = 0; i < STUDENTS; i++)  // �ݺ��� i�� STUDENTS(5) ���� ���������� �ݺ�, 1�� ������
		sum += scores[i];  // sum = sum + scores[i] -> �������� ���س����� ��
		
	return sum;  // sum �� ��ȯ
}

double averageScores(int scores[]) {
	int sum = sumScores(scores);
	int num = 5;
	double average;  // double��
	average = (double)sum / (double)num;  // ��ձ��ϱ�, int���� double������ ����ȯ�ߴ�. �տ��ٰ� num ������ ��ձ��ϱ�.

	return average;  // average ��ȯ
}


void printRanks(int scores[]) {
// 2�� for�� ���
	for (int i = 0; i < STUDENTS; i++) {  
		int ranks = 1;
		for (int j = 0; j < STUDENTS; j++) {
			if (scores[i] >= scores[j])
				ranks = ranks + 0;  // ���� scores[i] >= scores[j] ��� ��µ�. �̶��� 1��� ��ȭ�� ��� �Ǵϱ� ranks�� 0���ϱ⸦ �ߴ�.
			else
				ranks = ranks + 1;  // scores[i] < scores[j] �϶� ��µ�. 1� 1 ���ؼ� 2������ �������� ������ ���� �϶��� �����.
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
	printf("�л����� ������ �� ���� %d�̰�, ��� ���� %lf�Դϴ�.\n", sum, average);  // sum, average ����־ ��µ�.

	printRanks(scores);

	return 0;
}

