#include <stdio.h>

int hapf(int value);  //�Լ� ���� ����

void main()  //ȣ����
{
	printf("1����     10������ ���� %d\n", hapf(10));
	printf("1����    100������ ���� %d\n", hapf(100));
	printf("1����  1000������ ���� %d\n", hapf(1000));  // hapf�Լ� ȣ���ؼ� ��ȯ���� ����Ѵ�.
}

int hapf(int value)  //��ȣ����, �Լ����� hapf�̴�.
{
	int i;
	int hap = 0;  // ���� ���� �� �ʱ�ȭ

	i = 1;
	while (i <= value) {  // i<=value �϶����� �ݺ�
		hap = hap + i;
		i = i + 1;  // i�� 1, 2, 3... 1�� �������� i�� �ȴ�.
	}
	return hap;  // int������ hap(�����) ��ȯ
}
