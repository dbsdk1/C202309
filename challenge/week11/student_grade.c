#include <stdio.h>
#define STUDENTS 5  // 컴파일 될 때 상수값 정의됨

void ClassifyStudents(int *scores,
                      char targetGrade) {  // 주소를 받으니까 포인터 변수로 받기
  printf("학생 성적 분류:\n");
  char grade = ' ';
  for (int i = 0; i < STUDENTS; i++) {  // i가 0부터 시작하고 한번 돌고나면 1씩
                                        // 증가, i가 5보다 작을때까지 반복
    if (*(scores + i) >=  // 포인터 연산 사용
        90) {  // 배열, 만약 i에 0 들어감 -> 배열의 크기는 0이다.
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
      printf("%d 학생은 %c 점수를 받았습니다.\n", i + 1,
             targetGrade);  // targetGrade와 grade가 같으면 출력, %d에는 i+1의
                            // 값이 넣어지고 %c에는 targetGrade 넣어짐.
    }
  }
}

int SumScores(int *scores) {  // sumScores라는 함수이다.
  int sum = 0;
  for (int i = 0; i < STUDENTS;
       i++)  // 반복문 i가 STUDENTS(5) 보다 작을때까지 반복, 1씩 더해짐
    sum += *(scores + i);  // 포인터 연산

  return sum;  // sum 값 반환
}

double AverageScores(int *scores) {
  int sum = SumScores(scores);
  int num = 5;
  double average;  // double형
  average =
      (double)sum / (double)num;  // 평균구하기, int형을 double형으로
                                  // 형변환했다. 합에다가 num 나눠서 평균구하기.

  return average;  // average 반환
}

void PrintRanks(int *scores) {
  // 2중 for문 사용
  int ranks[STUDENTS];
  for (int i = 0; i < STUDENTS; i++) {
    ranks[i] = 1;  // 맨처음에 순위를 1로 설정함.
    for (int j = 0; j < STUDENTS; j++) {
      if (*(scores + j) >
          *(scores + i)) {  // 역참조!!! 배열에 담긴 값에 접근, scores 배열에
                            // 담긴 값임 증가하면서 접근함
        ranks[i]++;
      }
    }
    printf("%d 학생의 순위는 %d 입니다.\n", i + 1, ranks[i]);
  }
}

int main() {
  int scores[STUDENTS];
  for (int i = 0; i < STUDENTS; i++) {
    printf("학생 %d의 성적을 입력하세요: ",
           i + 1);  // 학생 1, 2, 3 이렇게 커지며 출력됨.
    scanf_s("%d", &scores[i]);
  }

  char ch = getchar();  // 버퍼 임시 저장 변수, 엔터지우기 위해

  char target;  // char형
  printf("특정 점수 (A,B,C,D,F)를 입력하시오: ");
  scanf_s("%c", &target, 1);  // 사용자로부터 값 입력받음

  ClassifyStudents(scores, target);

  int sum = SumScores(scores);  // scores(주소임) 전달해줌
  double average = AverageScores(scores);
  printf("학생들의 점수의 총 합은 %d이고, 평균 값은 %lf입니다.\n", sum,
         average);  // sum, average 집어넣어서 출력됨.

  PrintRanks(scores);

  return 0;
}
