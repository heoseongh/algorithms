#include <stdio.h>
#define NUM 10

int main(void){
	int i, j, temp;
	int array[NUM] = {1, 10, 5, 8, 7, 6, 4, 3, 2, 9};
	for(i = 0; i < NUM - 1; i++){
		j = i;
		while(array[j] > array[j+1]){
			temp = array[j];
			array[j] = array[j+1];
			array[j+1] = temp;
			j--;
		}
	}
	for(i = 0; i < NUM; i++){
		printf("%d ", array[i]);
	}
}
