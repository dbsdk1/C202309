#include <stdio.h>
#define MAX_TASKS 10
#define CHAR_NUM 100
#include <string.h>

char tasks[MAX_TASKS][CHAR_NUM] = { "" }; // �� �� ����� �����ϱ� ���� 2���� �迭
int taskCount = 0; // �� �� ���� �����ϴ� ����


void addTask(char task[]) {// �Լ� ����
	printf("�� ���� �Է��ϼ��� (���� ���� �Է��ϼ���): ");
	scanf_s("%s", task, (int)sizeof(task));
	strcpy_s(tasks[taskCount], sizeof(tasks[taskCount]), task);  // task[taskCount]�� �� �� ����(taskCount�� 0���� ��), ����� ���ֱ�
	printf("�� �� ""%s""�� ����Ǿ����ϴ�\n\n", task);  // task[taskCount]�� ����� ���ڿ� ���
}

void delTask(int delIndex, int taskCount) {

	printf("%d. %s : �� ���� �����մϴ�.\n", delIndex, tasks[delIndex - 1]);  // delIndex���� 1�� ���� �� ���� �ε����� ��������!

	// �Է��� ��ȣ�� �� �� ���� �� �ڿ� �ִ� �� ���� ������ �ű�.
	for (int i = delIndex; i < taskCount + 1; i++) {
		strcpy_s(tasks[i - 1], sizeof(tasks[i]), tasks[i]);
	}
}

void printTask(int taskCount) {
	for (int i = 0; i < taskCount; i++) {  // for �ݺ��� i�� taskCount���� ���� ������ �ݺ�
		printf("%d. %s \n", i + 1, tasks[i]);  // i�� 0���Ϳ��� ������ ����� �� 1���� ��µǵ��� %d�� �� ���� 1�� ���ߴ�. %s���� tasks[i] ���ڿ��� ���� ��µȴ�.
	}
	printf("\n");
}

int main() {
	printf("TODO ����Ʈ ����! \n");

	while (1) {
		int choice = -1; // ����� �Է� �޴��� �����ϱ� ���� ����

		// �����ϸ� �� ����Ʈ �ǰ� scanf_s�� ��ȣ�� �Է¹ް� �Ѵ�.
		printf("------------------\n");
		printf("�޴��� �Է����ּ���.\n");
		printf("1. �� �� �߰�\n2. �� �� ����\n3. ��� ����\n4. ����\n5.�� �� ����\n");
		printf("���� �� �� �� = %d\n", taskCount);
		printf("------------------\n");
		scanf_s("%d", &choice);

		int terminate = 0; // ���α׷� ���Ḧ ���� ����
		int delIndex = -1;  // �� �� ���� �ε��� ��ȣ ���� ����

		int changeIndex = -1; // �� �� ���� �ε��� ��ȣ ���� ����
		char ch; // ���� ����

		// ����ġ��
		switch (choice) {
		case 1:
			addTask(tasks[taskCount]);  // �Լ� ȣ��
			taskCount++;  // �� �� ������ �þ.
			break;
		case 2:// �� �� �����ϴ� �ڵ� ��� 
			printf("������ �� ���� ��ȣ�� �Է����ּ���. (1���� ����):");
			scanf_s("%d", &delIndex);  // ����ڰ� �Է��� ���� delIndex�� ����
			if (delIndex > taskCount || delIndex <= 0) {  // ���� ���� �ε�����ȣ�� �� �� ������ ���ų� 0�̶� ���ų� ������(��, ��� ���)
				printf("���� ������ ������ϴ�.\n");
			}
			else {
				delTask(delIndex, taskCount);  // �Լ� ȣ��
				taskCount -= 1;  // �� �� ���� ����
			}
			break;
		case 3:
			printf("�� �� ���\n");
			printTask(taskCount);  // �Լ� ȣ��
			break;
		case 4:  // ���α׷� ����
			terminate = 1;
			break;
		case 5:
			printf("������ �� ���� ��ȣ�� �Է��ϼ���.\n");
			scanf_s("%d", &changeIndex);  // ������ �� ��ȣ �Է¹ޱ�
			if (changeIndex > taskCount || changeIndex <= 0) {  // changeIndex�� taskCount���� ũ�ų� 0���� �۰ų� ������ 
				printf("���� ������ ������ϴ�.\n");
				break;
			}
			else {
				strcpy_s(tasks[changeIndex - 1], sizeof(tasks[changeIndex - 1]), "");  // tasks[changeIndex - 1] ����� �Լ�

			}
			// �� �ڸ��� ������ �� �Է¹ޱ�
			printf("�� ���� �Է��ϼ���.\n");
			ch = getchar();  // ���� ����
			scanf_s("%s", tasks[changeIndex - 1], (int)sizeof(tasks[changeIndex - 1]));
			break;
		default:  // 1, 2, 3, 4, 5 ���� ���� �Է��� ��� ���
			printf("�߸��� �����Դϴ�. �ٽ� �����ϼ���.\n");
		}

		if (terminate == 1) {  // case4���� terminate�� 1�� �Ǵµ� �̶� �����ϰ� ����� if���̴�.
			printf("���Ḧ �����ϼ̽��ϴ�. ���α׷��� �����մϴ�.\n");
			break;
		}
		if (taskCount == 10) {  // �� �� ������ 10�� �Ǹ� ���α׷��� �����ϰ� ����� if��
			printf("�� ���� %d���� �� á���ϴ�.", taskCount);
			break;
		}
	}
	return 0;
}