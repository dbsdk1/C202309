#include <stdio.h>
#define NUMCITY 3
#define NUMPEOPLE 2

char names[NUMPEOPLE][10];  // 2���� �迭, NUMPEOPLE�� 2�ϱ� ���� 2�� ���� 10
char cities[NUMCITY][10]; // �� 3 �� 10

void calculateTravelDays();  // �Լ� ����

int main() {

	//����ڷκ��� ���� �̸� �Է¹ޱ�
	printf("%d���� ���ø��� ���ʴ�� �Է����ּ���.\n", NUMCITY);
	for (int i = 0; i < NUMCITY; i++) {  // for �ݺ���, i�� 0���� �����ؼ� NUMCITY���� ���� ������ �ݺ��ϰ� i�� 1�����س�����
		scanf_s("%s", cities[i], (int)sizeof(cities[i]));  // ����ڷκ��� �Է� ����. ���ڿ��� �Է¹޴´�! �����ͻ����� ���ϴ� sizeof�� �̿���
	}

	//����ڷκ��� ��� �̸� �Է¹ޱ�
	printf("%d���� ������ �̸��� ���ʴ�� �Է����ּ���.\n", NUMPEOPLE);
	for (int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));  // ���� ����.
	}


	calculateTravelDays();  // �Լ� ȣ����

	return 0;
}
int getSum(int numArray[], int length) {  // getSum�Լ�, ��ȣ ���� �Է¹��� �͵�
	int totalDays = 0;
	for (int i = 0; i < length; i++) {  // for �ݺ������� i�� length���� ���� ������ �ݺ���
		totalDays += numArray[i];  // �� �ӹ����� ����ϴ� ��
	}
	return totalDays;  // �Ѹӹ��� ��ȯ
}
double getAverage(int numArray[], int length) {  
	int totalDays = 0;
	for (int i = 0; i < length; i++) { 
		totalDays += numArray[i];
	}
	double averageDays = (double)totalDays / length;  // ����� ���ϱ� ���� totalDays�� double������ ����ȯ�ϰ� length�� ����.
	return averageDays;  // double������ ��ȯ
}
void printfFamousCity(double dayArray[], int length) {
	double maxDay = 0;
	int maxDayIndex = 0;
	for (int i = 0; i < length; i++) {
		if (dayArray[i] > maxDay) {  // 0���� �����ϱ� �����ؼ� ���� ���� �� �־ ���� �α��ִ� ���� ���� �� �ִ�.
			maxDay = dayArray[i];  // ���� dayArray[i]�� �� ũ�ٸ� maxDay�� ������.
			maxDayIndex = i;  // �ε��� ��Ͽ�
		}
	}
	printf("����� �������� ���� �α��־��� ���ô� %s �Դϴ�. (��� �ӹ���: %.2f)\n", cities[maxDayIndex], maxDay);  // %s�� ���ڿ� ����ϴ� ���̴�. %.2f�� �Ҽ� ��°�ڸ����� ��µ�, cities[]<- ���⿡ i ����־����� ������ �����̸��� ��µȴ�.
}

void calculateTravelDays() {  // �Լ�
	int travelDays[NUMCITY][NUMPEOPLE];

	//�� ���ÿ��� �� ����� ���� �� �� �Է¹ޱ�
	for (int i = 0; i < NUMCITY; i++) {
		for (int j = 0; j < NUMPEOPLE; j++) {  // 2�� for��
			printf("���� %s���� ��� %s�� ���� �� ���� �Է��ϼ���: ", cities[i], names[j]);  // �迭, ������ ����ڰ� �Է��ؼ� �� ĭ�� ����Ǿ��� ���ڿ��� ���
			scanf_s("%d", &travelDays[i][j]);   // ó������ travelDays[0][0] <- �� �ڸ��� ����
		}
	}
	double averageDays[NUMCITY];
	//�� ���ú� �� �� �� �� ��� �� �� ��� �� ���
	for (int i = 0; i < NUMCITY; i++) {
		int totalDay = getSum(travelDays[i], NUMPEOPLE);  // �Լ�ȣ���ؼ� �װ��� totalDay�� ����
		double averageDay = getAverage(travelDays[i], NUMPEOPLE);  // �Լ�ȣ��
		printf("���� %s���� ���� �� �ϼ� : %d, ��� �� �� : %.2f\n", cities[i], totalDay, averageDay);
		averageDays[i] = averageDay;
	}
	printfFamousCity(averageDays, NUMCITY);
}
