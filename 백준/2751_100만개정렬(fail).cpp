#include <stdio.h>
#define NUM 1000001

int number, data[NUM];

void quickSort(int *data, int start, int end){
	if(start >= end){	//���Ұ� 1���� ��� �ٷ� ����. 
		return; 
	}
	int pivot = start;	//ó�� ���ذ��� ���� ��. 
	int i = start + 1, j = end, temp;
	while(i <= j){
		while(data[i] <= data[pivot]){
			i++;
		}
		while(data[j] >= data[pivot] && j > start){ 
			j--;
		}
		if( i > j){		//������ ���. ���ذ�(pivot)�� ���� ��(j)�� �ٲ���. 
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		} else {		//�׷��� ���� ���. ���� ��(j)�� ū ��(i)�� �ٲ���. 
			temp = data[i];
			data[i] = data[j];
			data[j] = temp;
		}
	}
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}
int main(void){
	scanf("%d", &number);
	for(int i = 0; i < number; i ++){
		scanf("%d", &data[i]);
	}
	quickSort(data, 0, number - 1);
	for(int i = 0; i < number; i ++){
		printf("%d\n", data[i]);
	}
}
//while(data[j] >= data[pivot] && j > start) ���⼭
//j > start �� �� �ִ� ����!! 
//�������� �� ������ ���� pivot ���� �ٲ��ֱ� ������
//j�� ���ʿ� �ִ� ���� ħ���� �� ������
//������ �����������.
