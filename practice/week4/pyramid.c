#include <stdio.h>

int main() {
	int floor;  // ���� ���� �� �ʱ�ȭ
	printf("�� ������ �װڽ��ϱ�? (5~100)");
	scanf_s("%d", &floor);  // �� �Է¹ް� floor�� ����

	for (int i = 0; i < floor; i++) // �ݺ���for ��� i�� floor���� ���������� �ݺ�, i�� 1�� ���س���.
	{
		// ���߹ݺ���
		for (int j = 0; j < floor - 1-i ; j++) {  // 4,3,2,1,0 ó�� �پ���. j�� floor-1-i���� ���������� �ݺ�, j���� 1�� ���س���.
			printf("S");
		}
		for (int k = 0; k < i * 2 + 1; k++) {
			printf("*");  // �� ������ 1,3,5,7,9 (i*2+1)��ŭ ��µ�.

		}
		printf("\n"); // �ٹٲ㼭 �Ƕ�̵� ����� ������ �Ѵ�.


	}



	return 0;
}