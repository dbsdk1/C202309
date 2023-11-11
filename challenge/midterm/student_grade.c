#include <stdio.h>
#define STUDENTS 5
#define SUBJECTS 3
#define CHARNUM 20

void printStudentResults(double studentScores[][SUBJECTS],
                         char studentNames[][CHARNUM]) {
  for (int i = 0; i < STUDENTS; i++) {
    double sum = 0;
    for (int j = 0; j < SUBJECTS; j++) {
      sum += studentScores[i][j];  // studentScores�� �迭�� ��� �� �ϳ��ϳ���
                                   // �����ؼ� �� ���ؼ� �� ���� sum�� ���Ѵ�.
    }  // 00 01 02���� ���� (�л����� ���ϱ� ���ؼ�)
    double finalScore = (double)sum / SUBJECTS;  // ��� ���ϱ�
    printf("\t%s�� ��� ����: %.2lf\n", studentNames[i],
           finalScore);  // �л��̸� ���ڿ��� �����ؼ� �̸� ���
  }
}

void printSubjectResults(double studentScores[][SUBJECTS],
                         char subjectNames[][CHARNUM]) {
  for (int i = 0; i < SUBJECTS; i++) {
    double sum = 0;
    for (int j = 0; j < STUDENTS; j++) {
      sum += studentScores[j][i];  // ��������̱⶧���� 00 10 20 ���� �迭��
                                   // ����! (���� �����̱⶧����)
    }
    double subjectScore = (double)sum / STUDENTS;  // ���� ��� ���ϱ�
    printf("\t%s�� ��� ����: %.2lf\n", subjectNames[i], subjectScore);
  }
}

int main() {
  char subjectNames[SUBJECTS][CHARNUM] = {"����", "�߰����", "�⸻���"};
  char studentNames[STUDENTS][CHARNUM] = {""};  // �л� �̸��� ����� �迭
  double studentScores[STUDENTS][SUBJECTS] = {
      0.0};  // �л��� ���� �� ������ ������ ����� �迭
  printf("�л� %d���� �̸��� �Է��� �����մϴ�. \n", STUDENTS);
  // TODO 1.1: �л� �̸��� �Է¹޴� �ڵ� ��� �ۼ�
  for (int i = 0; i < STUDENTS; i++) {
    printf("	%d��° �л��� �̸��� �Է��ϼ���. ", i + 1);
    scanf_s("%s", studentNames[i],
            (int)sizeof(studentNames[i]));  // �л��̸� �迭�� �����Ű��
  }

  // �Էµ� �л� �̸��� �� ����Ǿ����� Ȯ���ϴ� �ڵ� ���
  printf("�л� �̸��� ��� �ԷµǾ����ϴ�. \n");

  printf("�Էµ� �л� �̸��� ������ �����ϴ�. \n");
  for (int i = 0; i < STUDENTS; i++) {
    printf("%s", studentNames[i]);
    if (i != STUDENTS - 1) {
      printf(", ");
    }
  }
  printf("\n");
  printf("--------------------\n");
  printf(
      "�� �л��� %s, %s, %s ������ ���ʴ�� �Է����ּ���. (���� ����)\n ",
      subjectNames[0], subjectNames[1], subjectNames[2]);

  // TODO 1.2: �л����� ���� �� ������ �Է¹޴� �ڵ� ��� �ۼ�
  for (int i = 0; i < STUDENTS; i++) {
    int j = 0;
    getchar();
    printf("	%s�� ���� ", studentNames[i]);
    scanf_s(
        "%lf %lf %lf", &studentScores[i][j], &studentScores[i][j + 1],
        &studentScores[i][j + 2]);  // studentScores(2���� �迭)�� �л��� ������
                                    // �Է¹޴´�. 00 01 02, 10 11 12 �����̹Ƿ�
                                    // �� �л��� ���� �߰���� �⸻��縦
                                    // �ǹ��ϴ� �迭ĭ�� ���� �־�����.
  }

  printf("�л����� ���� ������ ��� �Է� �Ǿ����ϴ�.\n");
  printf("--------------------\n");
  printf("�л� �� ������ ������ �����ϴ� \n");

  // TODO 1.3: �л� �� ��� ������ ����ϴ� �ڵ� ��� �ۼ� >> ���� �Լ�ȭ
  // HINT1: 2�� for��: (1) �л��� (2) ������� ���� �հ� ����� ���ϰ� ���
  // HINT2: ��¹� �ڵ� = printf("\t%s�� ��� ����: %.2lf\n", studentNames[i],
  // finalScore);
  printStudentResults(studentScores, studentNames);  // �Լ� ȣ��

  printf("--------------------\n");
  printf("���� �� ��� ������ �Ʒ��� �����ϴ�. \n");
  // TODO 1.4: ���� �� ��� ������ ����ϴ� �ڵ� ��� �ۼ� >> ���� �Լ�ȭ
  // HINT1: 2�� for������ (1) ���� (2) �л����� ���� �հ� ����� ���ϰ� ���
  // HINT2: ��¹� �ڵ� = printf("\t%s�� ��� ������ %.2lf �Դϴ�.\n",
  // subjectNames[i], subjectScore);
  printSubjectResults(studentScores, subjectNames);

  printf("���α׷��� �����մϴ�. ");
  return 0;
}