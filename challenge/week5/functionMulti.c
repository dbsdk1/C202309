#include <stdio.h>

long multiF(long value);  //�Լ� ���� ����

int main()  //ȣ����
{
	printf("1����     2������ ���� %ld\n", multiF(2));
	printf("1����    3������ ���� %ld\n", multiF(3));
	printf("1����    5������ ���� %ld\n", multiF(5));  // multiF�Լ� ȣ���ؼ� ��ȯ���� ����Ѵ�.
	return 0;
}

long multiF(long value)  // �Լ���: multiF
{
	long i;
	long multi = 1;

	i = 1;
	while (i <= value) {  // i<=value �϶����� �ݺ�
		multi = multi * i;  // 1x1, 1x2, 2x3 �̷������� ������.
		i = i + 1;  //i�� 1, 2, 3... 1�� ������
	}
	return multi;  // long������ ����� ��ȯ
}
