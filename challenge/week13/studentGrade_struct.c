#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {  // �����ϰ� �̸��� ������ Student ����ü �����!!
  char *name;
  int score;
};

void initializeStudentInfo(struct Student *student);  // �Լ� ���� ����

void ClassifyStudents(struct Student *student, char targetGrade,
                      int numstudents)  // ����ü�� �Լ����� ����ߴ�.
{
  printf("�л� ���� �з�:\n");
  char grade = ' ';
  for (int i = 0; i < numstudents; i++) {
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
    if (targetGrade == grade) {
      printf("%d �л��� %c ������ �޾ҽ��ϴ�.\n", i + 1,
             targetGrade);  // Ÿ������ ���� ������ if���� grade�� ������ �����
                            // �ȴ�.
    }
  }
}

int SumScores(struct Student *student, int numstudents) {
  int sum = 0;
  for (int i = 0; i < numstudents; i++) {
    sum += student[i].score;  // student[i].score�� �ִ� ��(����ڰ� �Է��ߴ�
                              // ������ �� ����)�� sum�� ���ؼ� ���� ���ϱ�
  }  // �ݺ����̶� �л����� ����� ���� ��ҿ� ��� �����ؼ� ���� �� �ִ�.

  return sum;  // sum �� ��ȯ
}

double AverageScores(struct Student *student, int numstudents) {
  int sum = SumScores(student, numstudents);
  double average;  // double��
  average = (double)sum /
            (double)numstudents;  // ��ձ��ϱ�, int���� double������
                                  // ����ȯ�ߴ�. �տ��ٰ� num ������ ��ձ��ϱ�.

  return average;  // average ��ȯ
}

void PrintRanks(struct Student *student, int numstudents) {
  // 2�� for�� ���
  int *rank = (int *)malloc(
      numstudents *
      sizeof(int));  // rank�� ���� �޸� �Ҵ��� ����ߴ�. (�ֳ��ϸ� ������
                     // rank[]���� ����� �ʿ��ϱ� �����̴�) ���� �޸�
                     // �Ҵ����� ����ڰ� �Է��� numstudents�� ��밡������.
  for (int i = 0; i < numstudents; i++) {
    *(rank + i) = 1;  // ��ó���� ������ 1�� ������.
    for (int j = 0; j < numstudents; j++) {
      if (student[j].score > student[i].score) {  // Student ����ü���� ���� ��� ������ �ҷ�����.
        rank[i]++;  // ������ ���ϸ鼭 ������ �� ���ٸ� �迭�� "��"�� 1�� ���ؼ� ������ 1�� ���ϵ��� ��.  
      }
    }
    printf("%d �л��� ������ %d �Դϴ�.\n", i + 1, *(rank + i));
  }
  free(rank);
}

int main() {
  int numstudents;
  printf("�л� ���� �Է��ϼ���. ");
  scanf_s("%d", &numstudents);  // ����ڰ� �л����� �Է��ϰ���.

  struct Student *student = (struct Student *)malloc(
      numstudents *
      sizeof(struct Student));  // ����ü ������ ����ؼ� �������� �迭 �Ҵ��ϱ�
                                // ������ ������ �����Ͽ� ����ϱ�. 
  if (student == NULL) {
    return 1;
  }

  for (int i = 0; i < numstudents; i++) {
    initializeStudentInfo(&student[i]);  // Student ����ü���ٰ� �Է�
  }

  char ch = getchar();

  char target;
  printf("Ư�� ���� (A,B,C,D,F)�� �Է��Ͻÿ�: ");
  scanf_s("%c", &target, 1);  // ����ڷκ��� Ÿ�������� �Է¹���

  ClassifyStudents(student, target, numstudents);

  int sum = SumScores(student, numstudents);
  double average = AverageScores(student, numstudents);
  printf("�л����� ������ �� ���� %d�̰�, ��� ���� %lf�Դϴ�.\n", sum,
         average);

  PrintRanks(student, numstudents);

  for (int i = 0; i < numstudents; i++) {
    free(student[i].name);
  }
  free(student);  // �� ���� ���� free�� �Ҵ�� �޸� �������ֱ�

  return 0;
}

void initializeStudentInfo(struct Student *student) {
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