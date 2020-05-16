#include <stdio.h>
#define NUM 8

int sorted[NUM];	//정렬 배열은 반드시 전역 변수!!!
					//merge 할 때마다 정렬된 data를 저장 할 배열을 만들게 되면 비효율적이기 때문.
void merge(int a[], int m, int middle, int n){
	int i = m;
	int j = middle + 1;
	int k = m;
	//작은 순서대로 배열에 삽입
	while(i <= middle && j <= n){
		if(a[i] <= a[j]){
			sorted[k] = a[i];
			i++;
		} else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	//남은 데이터도 삽입.
	if(i > middle){
		for(int l = j; l <= n; l++){
			sorted[k] = a[l];
			k++; 
		}
	} else {
		for(int l = i; l <= middle; l++){
			sorted[k] = a[l];
			k++;
		}
	} 
	//정렬된 배열을 실제 배열에 삽입
	for(int l = m; l <= n; l++){
		a[l] = sorted[l];
	} 
}

void mergeSort(int a[], int m, int n){
	//크기가 1보다 큰 경우.
	if(m < n){
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);		//왼쪽 쪼개기 
		mergeSort(a, middle + 1, n);	//오른쪽 쪼개기 
		merge(a, m, middle, n);			//다 쪼갰으면 합치기 
	}
}

int main(void){
	int array[NUM] = {7, 6, 5, 8, 3, 5, 9, 1};
	
	mergeSort(array, 0, NUM - 1);
	
	for(int i = 0; i < NUM; i++){
		printf("%d ", array[i]);
	}
} 
