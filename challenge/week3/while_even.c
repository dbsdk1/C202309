#include <stdio.h>

int main()
{
	int i = 0;  // ���� ���� �� �ʱ�ȭ
	
	// �ݺ���; (i<10) �϶����� �ݺ�
	while (i < 10) {  
		i++;
		if (i % 2 == 0) {
			continue;  // i�� ¦���� �Ѿ�� 
			
		}
		
		printf("%d Hello World!\n", i); // i�� �Բ� ��ο��� ���
		i++;  // i�� 1 ���ϱ�
	
		
	}
	return 0;
}