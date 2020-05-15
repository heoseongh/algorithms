#include <stdio.h>

int main(void){
	int array[3];
	int min, i, j, temp, index;
	
	for(i = 0; i < 3; i++){
		scanf("%d", &array[i]);
	}
	for(i = 0; i < 3; i++){
		min = 10000001;		//min 값은 항상 들어오는 값보다 커야하기 때문 
		for(j = i; j < 3; j++){
			if(min > array[j]){
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	for(i = 0; i < 3; i++){
		printf("%d ", array[i]);
	}
}
