#include <stdio.h>

int main()
{
	int i = 0;  // ���� ���� �� �ʱ�ȭ
	do {
		i++;
		if (i % 2 == 0) {
			continue;  // ¦������ ����ؼ� �����ŷ� �Ѿ�� ��� ����
		}
		printf("%d Hello World!\n", i);
	} while (i < 10);  // �ݺ���(i�� 10 �̸��϶�����)

}