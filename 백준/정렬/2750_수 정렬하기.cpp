//use Selection Sort 
#include <stdio.h>

int array[1001];	//*data 개수가 1000개 까지이므로 배열의 index는 0부터 시작하기 때문에
					//웬만해서 알고리즘 문제를 풀 때에는 최댓값+1 만큼의 배열 크기를 지정해 주는 것이 좋다. 
int main(void){
	int number, i, j, min, index, temp;
	scanf("%d", &number);
	for(i = 0; i < number; i++){
		scanf("%d", &array[i]);
	}
	for(i = 0; i < number; i++){
		min = 1001;		//절댓값이 1000보다 작거나 같은 정수이기 때문.
		for(j = i; j < number; j++){
			if(min > array[j]){
				min = array[j];
				index = j;
			}
		}
		temp = array[i];
		array[i] = array[index];
		array[index] = temp;
	}
	for(i = 0; i < number; i++){
		printf("%d\n", array[i]);
	}
} 
 
