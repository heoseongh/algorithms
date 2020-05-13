#include <stdio.h>
#define NUM 10

int data[NUM] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void quickSort(int *data, int start, int end){
	if(start >= end){ //���Ұ� 1���� ��� 
		return;		
	}
	
	int pivot = start;
	int i = start + 1;
	int j = end;
	int temp;
	
	while(i <= j){ //������ ������ �ݺ�
		while(data[i] <= data[pivot]){ //���� ������ ū ���� ���� �� ���� 
			i++;
		}
		while(data[j] >= data[pivot] && j > start){ //���� ������ ���� ���� ���� �� ����
			j--;									//�ε����� �������� ��� data[j]�� data[pivot] ���� swap �Ǳ� ������ 
		}											//j�� start ���� Ŀ���Ѵ�. 
		if(i > j){	//���� ������ ���¸� Ű ���� ��ü 
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		} else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
	//data[j]�� data[pivot]�� swap�� �� �̹Ƿ�
	//������ ��ģ data[j]�� �������� left / right �迭�� ������.
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}									

int main(void){
	quickSort(data, 0, NUM - 1);
	for(int i = 0; i < NUM; i++){
		printf("%d ", data[i]);
	}
}
