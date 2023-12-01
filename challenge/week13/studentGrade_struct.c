#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {  // �����ϰ� �̸��� ������ Student ����ü �����!!
  char *name;
  int score;
};

void InitializeStudentInfo(struct Student *student);  // �Լ� ���� ����

void ClassifyStudents(struct Student *student, char target_grade,
                      int num_students)  // ����ü�� �Լ����� ����ߴ�.
{
  printf("�л� ���� �з�:\n");
  char grade = ' ';
  for (int i = 0; i < num_students; i++) {
    if (student[i].score >=
        90) {  // �ݺ������� ����ڰ� �Է��ߴ� ������ ����ü �迭�� ����
               // if������ ���� ���� ABCD �з� �۾��� �Ѵ�.
      grade = 'A';
    } else if (student[i].score >= 80) {
      grade = 'B';
    } else if (student[i].score >= 70) {
      grade = 'C';
    } else if (student[i].score >= 60) {
      grade = 'D';
    } else {
      grade = 'F';
    }
    if (target_grade == grade) {
      printf("%d �л��� %c ������ �޾ҽ��ϴ�.\n", i + 1,
             target_grade);  // Ÿ������ ���� ������ if���� grade�� ������ �����
                            // �ȴ�.
    }
  }
}

int SumScores(struct Student *student, int num_students) {
  int sum = 0;
  for (int i = 0; i < num_students; i++) {
    sum += student[i].score;  // student[i].score�� �ִ� ��(����ڰ� �Է��ߴ�
                              // ������ �� ����)�� sum�� ���ؼ� ���� ���ϱ�
  }  // �ݺ����̶� �л����� ����� ���� ��ҿ� ��� �����ؼ� ���� �� �ִ�.

  return sum;  // sum �� ��ȯ
}

double AverageScores(struct Student *student, int num_students) {
  int sum = SumScores(student, num_students);
  double average;  // double��
  average = (double)sum /
            (double)num_students;  // ��ձ��ϱ�, int���� double������
                                  // ����ȯ�ߴ�. �տ��ٰ� num ������ ��ձ��ϱ�.

  return average;  // average ��ȯ
}

void PrintRanks(struct Student *student, int num_students) {
  // 2�� for�� ���
  int *rank = (int *)malloc(
      num_students *
      sizeof(int));  // rank�� ���� �޸� �Ҵ��� ����ߴ�. (�ֳ��ϸ� ������
                     // rank[]���� ����� �ʿ��ϱ� �����̴�) ���� �޸�
                     // �Ҵ����� ����ڰ� �Է��� numstudents�� ��밡������.
  for (int i = 0; i < num_students; i++) {
    *(rank + i) = 1;  // ��ó���� ������ 1�� ������.
    for (int j = 0; j < num_students; j++) {
      if (student[j].score >
          student[i].score) {  // Student ����ü���� ���� ��� ������ �ҷ�����.
        rank[i]++;  // ������ ���ϸ鼭 ������ �� ���ٸ� �迭�� "��"�� 1��
                    // ���ؼ� ������ 1�� ���ϵ��� ��.
      }
    }
    printf("%d �л��� ������ %d �Դϴ�.\n", i + 1, *(rank + i));
  }
  free(rank);
}

int main() {
  int num_students;
  printf("�л� ���� �Է��ϼ���. ");
  scanf_s("%d", &num_students);  // ����ڰ� �л����� �Է��ϰ���.

  struct Student *student = (struct Student *)malloc(
      num_students *
      sizeof(struct Student));  // ����ü ������ ����ؼ� �������� �迭 �Ҵ��ϱ�
                                // ������ ������ �����Ͽ� ����ϱ�.
  if (student == NULL) {
    return 1;
  }

  for (int i = 0; i < num_students; i++) {
    InitializeStudentInfo(&student[i]);  // Student ����ü���ٰ� �Է�
  }

  char ch = getchar();

  char target;
  printf("Ư�� ���� (A,B,C,D,F)�� �Է��Ͻÿ�: ");
  scanf_s("%c", &target, 1);  // ����ڷκ��� Ÿ�������� �Է¹���

  ClassifyStudents(student, target, num_students);

  int sum = SumScores(student, num_students);
  double average = AverageScores(student, num_students);
  printf("�л����� ������ �� ���� %d�̰�, ��� ���� %lf�Դϴ�.\n", sum,
         average);

  PrintRanks(student, num_students);

  for (int i = 0; i < num_students; i++) {
    free(student[i].name);
  }
  free(student);  // �� ���� ���� free�� �Ҵ�� �޸� �������ֱ�

  return 0;
}

void InitializeStudentInfo(struct Student *student) {
  printf("�л� �̸��� �Է��ϼ���: ");
  char temp[100];
  scanf_s("%s", temp, (int)sizeof(temp));
  student->name = (char *)malloc(
      (strlen(temp) + 1) *
      sizeof(char));  // �л� �̸��� �Է¹��� �� �������� �޸𸮸� �Ҵ��Ѵ�.
  strcpy_s(student->name, strlen(temp) + 1,
           temp);  // �� �� name ���⿡��(�̸� �����ϴ� ����)�� ����ڰ� �Է���
                   // �л��̸��� �����Ѵ�.

  printf("�л� ������ �Է��ϼ���: ");
  scanf_s(
      "%d",
      &student->score);  // �л� ������ �Է¹޾Ƽ� Student ����ü�� �����Ѵ�.
                         // score(������ �����ϴ� ����)�� �����ϴ� ���̴�.
}