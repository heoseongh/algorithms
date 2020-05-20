#include <stdio.h>
#define NUM 3
int main(void) {
	int temp;
	int count[3]; 
	int array[20] = { 
		1, 2, 2, 1, 3, 
		1, 3, 3, 2, 1, 
		1, 2, 2, 1, 3, 
		2, 1, 3, 3, 3
	}
	//배열 초기화 
	for(int i = 0; i < NUM; i++) {
		count[i] = 0;
	}
	for(int i = 0; i <20; i++) {
		count[array[i] - 1]++;		//1 -> count[0]++ 2 -> count[1]++
	} 
	for(int i = 0; i < NUM; i++) {
		if(count[i] != 0) {
			for(int j = 0; j < count[i]; j++) {
				printf("%d", i + 1);
			}
		}
	}

	return 0;
}

