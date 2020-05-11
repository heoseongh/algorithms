#include <stdio.h>
#define NUM 10

int main(void){
	int i, j, temp;
	int array[NUM] = {1, 10, 5, 8, 7, 6, 4, 3, 2 ,9};
	for(i = 0; i < NUM; i++){
		for(j = 0; j <NUM - i - 1; j++){	
			if(array[j] > array[j+1]){
				temp = array[j];
				array[j] = array[j+1];
				array[j+1] = temp;
			}
		}
	}
	for(i = 0; i < NUM; i++){
		printf("%d ", array[i]);
	}
	return 0;
}
// 두 번째 for문에서 NUM - i - 1 로 설정해준 이유는
// 한 번만 실행해도 제일 큰 값을 찾을 수 있다.
// 따라서 마지막 숫자는 굳이 비교할 필요가 없다.
