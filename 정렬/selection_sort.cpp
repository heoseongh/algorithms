#include <stdio.h>
#define NUM 10

int main(void){
	int i, j, min, index, temp;
	int array[NUM] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for(i = 0; i < NUM; i++){
		min = 9999;		//��� ���ҵ� ���� ū ������ ���� �־��ش�. 
		for(j = i; j < NUM; j++){	//�������� ��ġ�� �������ش�. 
			if(min > array[j]){
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	for(i = 0; i < 10; i++){
		printf("%d ", array[i]);
	}
	return 0;
}
