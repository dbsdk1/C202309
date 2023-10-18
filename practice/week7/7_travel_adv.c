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
	printf("%d개의 여행자 이름을 차례대로 입력해주세요.\n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));  // 위와 같다.
	}


	calculateTravelDays();  // 함수 호출함

	return 0;
}
int getSum(int numArray[], int length) {  // getSum함수, 괄호 안은 입력받을 것들
	int totalDays = 0;
	for (int i = 0; i < length; i++) {  // for 반복문으로 i가 length보다 작을 때까지 반복함
		totalDays += numArray[i];  // 총 머문일을 계산하는 식
	}
	return totalDays;  // 총머문일 반환
}
double getAverage(int numArray[], int length) {  
	int totalDays = 0;
	for (int i = 0; i < length; i++) { 
		totalDays += numArray[i];
	}
	double averageDays = (double)totalDays / length;  // 평균일 구하기 위해 totalDays를 double형으로 형변환하고 length로 나눔.
	return averageDays;  // double형으로 반환
}
void printfFamousCity(double dayArray[], int length) {
	double maxDay = 0;
	int maxDayIndex = 0;
	for (int i = 0; i < length; i++) {
		if (dayArray[i] > maxDay) {  // 0부터 대입하기 시작해서 전부 비교할 수 있어서 가장 인기있는 도시 구할 수 있다.
			maxDay = dayArray[i];  // 만약 dayArray[i]가 더 크다면 maxDay에 대입함.
			maxDayIndex = i;  // 인덱스 기록용
		}
	}
	printf("평균일 기준으로 가장 인기있었던 도시는 %s 입니다. (평균 머문일: %.2f)\n", cities[maxDayIndex], maxDay);  // %s는 문자열 출력하는 것이다. %.2f는 소수 둘째자리까지 출력됨, cities[]<- 여기에 i 집어넣어졌기 때문에 도시이름이 출력된다.
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
	double averageDays[NUMCITY];
	//각 도시별 총 일 수 및 평균 일 수 계산 및 출력
	for (int i = 0; i < NUMCITY; i++) {
		int totalDay = getSum(travelDays[i], NUMPEOPLE);  // 함수호출해서 그값을 totalDay에 대입
		double averageDay = getAverage(travelDays[i], NUMPEOPLE);  // 함수호출
		printf("도시 %s에서 보낸 총 일수 : %d, 평균 일 수 : %.2f\n", cities[i], totalDay, averageDay);
		averageDays[i] = averageDay;
	}
	printfFamousCity(averageDays, NUMCITY);
}
