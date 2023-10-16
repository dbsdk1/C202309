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
	printf("%d���� ������ �̸��� ���ʴ�� �Է����ּ���.\n", NUMCITY);
	for(int i = 0; i < NUMPEOPLE; i++) {
		scanf_s("%s", names[i], (int)sizeof(names[i]));  // ���� ����.
	}

	
	calculateTravelDays();  // �Լ� ȣ����

	return 0;
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
	//�� ���ú� �� �� �� �� ��� �� �� ��� �� ���
	for (int i = 0; i < NUMCITY; i++) {
		int totalDays = 0;
		for (int j = 0; j < NUMPEOPLE; j++) {
			totalDays += travelDays[i][j];  // �� �� ���� ���ϱ� ���� ��� ���س����� ��.
		}
		float averageDays = (float)totalDays / NUMPEOPLE;  // totalDays�� float������ ����ȯ��.
		printf("���� %s���� ���� �� �ϼ� : %d, ��� �� �� : %.2f\n", cities[i], totalDays, averageDays);
	}
}