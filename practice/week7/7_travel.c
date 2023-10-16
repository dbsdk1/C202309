#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

char names[NUMPEOPLE][10];  // 2차원 배열, NUMPEOPLE이 2니까 행이 2고 열이 10
char cities[NUMCITY][10]; // 행 3 열 10

void calculateTravelDays();  // 함수 원형

int main() {

	//사용자로부터 도시 이름 입력받기
	printf("%d개의 도시명을 차례대로 입력해주세요.\n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {  // for 반복문, i가 0부터 시작해서 NUMCITY보다 작을 때까지 반복하고 i에 1씩더해나가짐
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));  // 사용자로부터 입력 받음. 문자열을 입력받는다! 데이터사이즈 구하는 sizeof를 이용함
	}

	//사용자로부터 사람 이름 입력받기
	printf("%d개의 여행자 이름을 차례대로 입력해주세요.\n", NUMCITY);
	for(int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));  // 위와 같다.
	}

	
	calculateTravelDays();  // 함수 호출함

	return 0;
}
void calculateTravelDays() {  // 함수
	int travelDays[NUMCITY][NUMPEOPLE];

	//각 도시에서 각 사람이 보낸 일 수 입력받기
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {  // 2중 for문
			printf("도시 %s에서 사람 %s가 보낸 일 수를 입력하세요: ", cities[i], names[j]);  // 배열, 위에서 사용자가 입력해서 각 칸에 저장되어진 문자열을 출력
			scanf_s("%d", &travelDays[i][j]);   // 처음꺼는 travelDays[0][0] <- 이 자리에 저장
		}
	}
	//각 도시별 총 일 수 및 평균 일 수 계산 및 출력
	for (int i = 0; i < NUMCITY; i++) {
		int totalDays = 0;
		for (int j = 0; j < NUMPEOPLE; j++) {
			totalDays += travelDays[i][j];  // 총 일 수를 구하기 위해 계속 더해나가는 것.
		}
		float averageDays = (float)totalDays / NUMPEOPLE;  // totalDays가 float형으로 형변환됨.
		printf("도시 %s에서 보낸 총 일수 : %d, 평균 일 수 : %.2f\n", cities[i], totalDays, averageDays);
	}
}