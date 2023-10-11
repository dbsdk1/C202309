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
			printf("%d �л��� %c ������ �޾ҽ��ϴ�.", i + 1, targetGrade);  // targetGrade�� grade�� ������ ���, %d���� i+1�� ���� �־����� %c���� targetGrade �־���.

		}
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

	return 0;
}