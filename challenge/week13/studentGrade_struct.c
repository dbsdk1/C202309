#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {  // 성적하고 이름을 가지는 Student 구조체 만들기!!
  char *name;
  int score;
};

void initializeStudentInfo(struct Student *student);  // 함수 원형 선언

void ClassifyStudents(struct Student *student, char targetGrade,
                      int numstudents)  // 구조체를 함수에서 사용했다.
{
  printf("학생 성적 분류:\n");
  char grade = ' ';
  for (int i = 0; i < numstudents; i++) {
    if (student[i].score >=
        90) {  // 반복문으로 사용자가 입력했던 점수의 구조체 배열을 돌고
               // if문으로 값에 따라 ABCD 분류 작업을 한다.
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
      printf("%d 학생은 %c 점수를 받았습니다.\n", i + 1,
             targetGrade);  // 타겟으로 삼은 점수가 if문의 grade와 같으면 출력이
                            // 된다.
    }
  }
}

int SumScores(struct Student *student, int numstudents) {
  int sum = 0;
  for (int i = 0; i < numstudents; i++) {
    sum += student[i].score;  // student[i].score에 있는 값(사용자가 입력했던
                              // 점수가 들어가 있음)을 sum에 더해서 총합 구하기
  }  // 반복문이라서 학생마다 저장된 점수 요소에 모두 접근해서 더할 수 있다.

  return sum;  // sum 값 반환
}

double AverageScores(struct Student *student, int numstudents) {
  int sum = SumScores(student, numstudents);
  double average;  // double형
  average = (double)sum /
            (double)numstudents;  // 평균구하기, int형을 double형으로
                                  // 형변환했다. 합에다가 num 나눠서 평균구하기.

  return average;  // average 반환
}

void PrintRanks(struct Student *student, int numstudents) {
  // 2중 for문 사용
  int *rank = (int *)malloc(
      numstudents *
      sizeof(int));  // rank도 동적 메모리 할당을 사용했다. (왜냐하면 기존의
                     // rank[]에는 상수가 필요하기 때문이다) 동적 메모리
                     // 할당으로 사용자가 입력한 numstudents를 사용가능해짐.
  for (int i = 0; i < numstudents; i++) {
    *(rank + i) = 1;  // 맨처음에 순위를 1로 설정함.
    for (int j = 0; j < numstudents; j++) {
      if (student[j].score > student[i].score) {  // Student 구조체에서 점수 멤버 변수를 불러왔음.
        rank[i]++;  // 점수를 비교하면서 점수가 더 낮다면 배열의 "값"에 1을 더해서 순위에 1을 더하도록 함.  
      }
    }
    printf("%d 학생의 순위는 %d 입니다.\n", i + 1, *(rank + i));
  }
  free(rank);
}

int main() {
  int numstudents;
  printf("학생 수를 입력하세요. ");
  scanf_s("%d", &numstudents);  // 사용자가 학생수를 입력하게함.

  struct Student *student = (struct Student *)malloc(
      numstudents *
      sizeof(struct Student));  // 구조체 포인터 사용해서 동적으로 배열 할당하기
                                // 포인터 변수에 저장하여 사용하기. 
  if (student == NULL) {
    return 1;
  }

  for (int i = 0; i < numstudents; i++) {
    initializeStudentInfo(&student[i]);  // Student 구조체에다가 입력
  }

  char ch = getchar();

  char target;
  printf("특정 점수 (A,B,C,D,F)를 입력하시오: ");
  scanf_s("%c", &target, 1);  // 사용자로부터 타겟점수를 입력받음

  ClassifyStudents(student, target, numstudents);

  int sum = SumScores(student, numstudents);
  double average = AverageScores(student, numstudents);
  printf("학생들의 점수의 총 합은 %d이고, 평균 값은 %lf입니다.\n", sum,
         average);

  PrintRanks(student, numstudents);

  for (int i = 0; i < numstudents; i++) {
    free(student[i].name);
  }
  free(student);  // 꼭 잊지 말고 free로 할당된 메모리 해제해주기

  return 0;
}

void initializeStudentInfo(struct Student *student) {
  printf("학생 이름을 입력하세요: ");
  char temp[100];
  scanf_s("%s", temp, (int)sizeof(temp));
  student->name = (char *)malloc(
      (strlen(temp) + 1) *
      sizeof(char));  // 학생 이름을 입력받은 뒤 동적으로 메모리를 할당한다.
  strcpy_s(student->name, strlen(temp) + 1,
           temp);  // 그 후 name 여기에다(이름 저장하는 변수)가 사용자가 입력한
                   // 학생이름을 복사한다.

  printf("학생 점수를 입력하세요: ");
  scanf_s(
      "%d",
      &student->score);  // 학생 점수를 입력받아서 Student 구조체에 저장한다.
                         // score(점수를 저장하는 변수)에 저장하는 것이다.
}