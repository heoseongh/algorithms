#include <stdio.h>
#define NUM 8

int sorted[NUM];	//���� �迭�� �ݵ�� ���� ����!!!
					//merge �� ������ ���ĵ� data�� ���� �� �迭�� ����� �Ǹ� ��ȿ�����̱� ����.
void merge(int a[], int m, int middle, int n){
	int i = m;
	int j = middle + 1;
	int k = m;
	//���� ������� �迭�� ����
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
	//���� �����͵� ����.
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
	//���ĵ� �迭�� ���� �迭�� ����
	for(int l = m; l <= n; l++){
		a[l] = sorted[l];
	} 
}

void mergeSort(int a[], int m, int n){
	//ũ�Ⱑ 1���� ū ���.
	if(m < n){
		int middle = (m + n) / 2;
		mergeSort(a, m, middle);		//���� �ɰ��� 
		mergeSort(a, middle + 1, n);	//������ �ɰ��� 
		merge(a, m, middle, n);			//�� �ɰ����� ��ġ�� 
	}
}

int main(void){
	int array[NUM] = {7, 6, 5, 8, 3, 5, 9, 1};
	
	mergeSort(array, 0, NUM - 1);
	
	for(int i = 0; i < NUM; i++){
		printf("%d ", array[i]);
	}
} 
