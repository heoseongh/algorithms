//use Selection Sort 
#include <stdio.h>

int array[1001];	//*data ������ 1000�� �����̹Ƿ� �迭�� index�� 0���� �����ϱ� ������
					//�����ؼ� �˰��� ������ Ǯ ������ �ִ�+1 ��ŭ�� �迭 ũ�⸦ ������ �ִ� ���� ����. 
int main(void){
	int number, i, j, min, index, temp;
	scanf("%d", &number);
	for(i = 0; i < number; i++){
		scanf("%d", &array[i]);
	}
	for(i = 0; i < number; i++){
		min = 1001;		//������ 1000���� �۰ų� ���� �����̱� ����.
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
 
