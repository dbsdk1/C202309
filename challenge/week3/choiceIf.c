#include <stdio.h>

int main() {
	int choice;  // ���� ���� �� �ʱ�ȭ

	printf("1. ���� ����\n");
	printf("2. ���� ���� �ݱ�\n");
	printf("3. ����\n");
	scanf_s("%d", &choice);  // ����ڷκ��� �� �Է¹޾Ƽ� choice�� ����

	if (choice == 1)  // 1�Է��ߴٸ�
	{
		printf("������ �����մϴ�.");
	}
	else if (choice == 2) {
		printf("���� ���� �ݽ��ϴ�.");  // 2�Է��ߴٸ� �̰� ��µ�
	}
	else if (choice == 3) {
		printf("�����մϴ�.");
	}
	else  // 1,2,3�� �ƴ� �ٸ� ���� �Է����� ���
		printf("�߸� �Է��ϼ̽��ϴ�.");  

	return 0;
}