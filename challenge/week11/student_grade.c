#include <stdio.h>
#define STUDENTS 5  // ������ �� �� ����� ���ǵ�

void ClassifyStudents(int *scores,
                      char targetGrade) {  // �ּҸ� �����ϱ� ������ ������ �ޱ�
  printf("�л� ���� �з�:\n");
  char grade = ' ';
  for (int i = 0; i < STUDENTS; i++) {  // i�� 0���� �����ϰ� �ѹ� ������ 1��
                                        // ����, i�� 5���� ���������� �ݺ�
    if (*(scores + i) >=  // ������ ���� ���
        90) {  // �迭, ���� i�� 0 �� -> �迭�� ũ��� 0�̴�.
      grade = 'A';
    } else if (*(scores + i) >= 80) {
      grade = 'B';
    } else if (*(scores + i) >= 70) {
      grade = 'C';
    } else if (*(scores + i) >= 60) {
      grade = 'D';
    } else {
      grade = 'F';
    }
    if (targetGrade == grade) {
      printf("%d �л��� %c ������ �޾ҽ��ϴ�.\n", i + 1,
             targetGrade);  // targetGrade�� grade�� ������ ���, %d���� i+1��
                            // ���� �־����� %c���� targetGrade �־���.
    }
  }
}

int SumScores(int *scores) {  // sumScores��� �Լ��̴�.
  int sum = 0;
  for (int i = 0; i < STUDENTS;
       i++)  // �ݺ��� i�� STUDENTS(5) ���� ���������� �ݺ�, 1�� ������
    sum += *(scores + i);  // ������ ����

  return sum;  // sum �� ��ȯ
}

double AverageScores(int *scores) {
  int sum = SumScores(scores);
  int num = 5;
  double average;  // double��
  average =
      (double)sum / (double)num;  // ��ձ��ϱ�, int���� double������
                                  // ����ȯ�ߴ�. �տ��ٰ� num ������ ��ձ��ϱ�.

  return average;  // average ��ȯ
}

void PrintRanks(int *scores) {
  // 2�� for�� ���
  int ranks[STUDENTS];
  for (int i = 0; i < STUDENTS; i++) {
    ranks[i] = 1;  // ��ó���� ������ 1�� ������.
    for (int j = 0; j < STUDENTS; j++) {
      if (*(scores + j) >
          *(scores + i)) {  // ������!!! �迭�� ��� ���� ����, scores �迭��
                            // ��� ���� �����ϸ鼭 ������
        ranks[i]++;
      }
    }
    printf("%d �л��� ������ %d �Դϴ�.\n", i + 1, ranks[i]);
  }
}

int main() {
  int scores[STUDENTS];
  for (int i = 0; i < STUDENTS; i++) {
    printf("�л� %d�� ������ �Է��ϼ���: ",
           i + 1);  // �л� 1, 2, 3 �̷��� Ŀ���� ��µ�.
    scanf_s("%d", &scores[i]);
  }

  char ch = getchar();  // ���� �ӽ� ���� ����, ��������� ����

  char target;  // char��
  printf("Ư�� ���� (A,B,C,D,F)�� �Է��Ͻÿ�: ");
  scanf_s("%c", &target, 1);  // ����ڷκ��� �� �Է¹���

  ClassifyStudents(scores, target);

  int sum = SumScores(scores);  // scores(�ּ���) ��������
  double average = AverageScores(scores);
  printf("�л����� ������ �� ���� %d�̰�, ��� ���� %lf�Դϴ�.\n", sum,
         average);  // sum, average ����־ ��µ�.

  PrintRanks(scores);

  return 0;
}
