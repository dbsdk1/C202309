#include <stdio.h>

int main() {
	int floor;  // ���� ���� �� �ʱ�ȭ
	printf("�� ������ �װڽ��ϱ�? (5~100)");
	scanf_s("%d", &floor);  // �� �Է¹ް� floor�� ����

	for (int i = floor; i > 0; i--)  // �ݺ����� �������� i�� 1�� ������.
	{
		
		for (int j = 0; j < floor - i; j++) {  // j�� floor���� i�� ������ ���������� �ݺ�, j�� 0���� ���� 1�� ���س����� 
			printf("S");  // floor-i��ŭ S��µ�.
		}
		for (int k = 1; k < i * 2; k++) {   
			printf("*");  // �������� ...3,1 ������ ��µȴ�.

		}
		printf("\n"); // �ٹٲ㼭 �Ƕ�̵� ����� ������ �Ѵ�.


	}



	return 0;
}