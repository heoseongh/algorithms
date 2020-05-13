#include <stdio.h>
#define NUM 10

int data[NUM] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};

void quickSort(int *data, int start, int end){
	if(start >= end){ //원소가 1개인 경우 
		return;		
	}
	
	int pivot = start;
	int i = start + 1;
	int j = end;
	int temp;
	
	while(i <= j){ //엇갈릴 때까지 반복
		while(data[i] <= data[pivot]){ //기준 값보다 큰 값을 만날 때 까지 
			i++;
		}
		while(data[j] >= data[pivot] && j > start){ //기준 값보다 작은 값을 만날 때 까지
			j--;									//인덱스가 엇갈렸을 경우 data[j]와 data[pivot] 값이 swap 되기 때문에 
		}											//j는 start 보다 커야한다. 
		if(i > j){	//현재 엇갈린 상태면 키 값과 교체 
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		} else {
			temp = data[j];
			data[j] = data[i];
			data[i] = temp;
		}
	}
	//data[j]와 data[pivot]이 swap된 후 이므로
	//정렬을 마친 data[j]를 기점으로 left / right 배열이 나뉜다.
	quickSort(data, start, j - 1);
	quickSort(data, j + 1, end);
}									

int main(void){
	quickSort(data, 0, NUM - 1);
	for(int i = 0; i < NUM; i++){
		printf("%d ", data[i]);
	}
}
