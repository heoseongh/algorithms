#include <stdio.h>
#define NUM 10

int main(void){
	int i, j, temp;
	int array[NUM] = {1, 10, 5, 8, 7, 6, 4, 3, 2 ,9};
	for(i = 0; i < NUM; i++){
		for(j = 0; j <NUM - i - 1; j++){	
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	for(i = 0; i < NUM; i++){
		printf("%d ", array[i]);
	}
	return 0;
}
// �� ��° for������ NUM - i - 1 �� �������� ������
// �� ���� �����ص� ���� ū ���� ã�� �� �ִ�.
// ���� ������ ���ڴ� ���� ���� �ʿ䰡 ����.
