#include <stdio.h>

int main() {
	int num = 0;  // ���� ���� �� �ʱ�ȭ
	printf("���ڸ� �Է��Ͻÿ�: ");  // �����ϸ� ���ڸ� �Է��϶�� ���
	scanf_s("%d", &num);  // ����ڷκ��� �� �Է¹ޱ�
	if (num == 0) {
		printf("zero");  // 0�� �Է��� ��� zero�� ���
	}
	else if (num == 1) {
		printf("one");  // 1�� �Է��� ��� one�� ���
	}
	else if (num == 2) {
		printf("two");  // 2�� �Է��� ��� two�� ���
	}
	else
		printf("not 0~2");  // 0, 1, 2 ��� �ƴ� ��� ��µǴ� �޼���

	return 0;
}