#include <stdio.h>
#define NUM 1000001

int number, data[NUM];

void quickSort(int *data, int start, int end){
	if(start >= end){	//원소가 1개인 경우 바로 종료. 
		return; 
	}
	int pivot = start;	//처음 기준값은 시작 값. 
	int i = start + 1, j = end, temp;
	while(i <= j){
		while(data[i] <= data[pivot]){
			i++;
		}
		while(data[j] >= data[pivot] && j > start){ 
			j--;
		}
		if( i > j){		//엇갈린 경우. 기준값(pivot)과 작은 값(j)을 바꿔줌. 
			temp = data[j];
			data[j] = data[pivot];
			data[pivot] = temp;
		} else {		//그렇지 않은 경우. 작은 값(j)과 큰 값(i)을 바꿔줌. 
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
//while(data[j] >= data[pivot] && j > start) 여기서
//j > start 를 해 주는 이유!! 
//엇갈렸을 때 왼쪽의 값과 pivot 값을 바꿔주기 때문에
//j는 왼쪽에 있는 값을 침범할 수 없도록
//영역을 제안해줘야함.
