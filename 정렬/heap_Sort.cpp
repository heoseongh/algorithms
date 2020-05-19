#include <stdio.h>
#define NUM 9

int heap[NUM] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

int main(void) {
	//��ü Ʈ�� ������ �ִ� �� ������ �����
	//Heapify algorithm O(logn) 
	for(int i = 1; i < NUM; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;		//Child-Node - 1 / 2 = Parent-Node
			if(heap[root] < heap[c]) {	//'�θ��� < �ڽĳ��'�̸� Swap 
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	//ũ�⸦ �ٿ����� �ݺ������� ���� ����.
	for(int i = NUM - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;

		//Heapify algorithm O(logn)
		do {
			c = 2 * root + 1;
			//�ڽ� �� �� ū �� ã��
			if(heap[c] < heap[c + 1] && c < (i - 1)) {
				c++;
			} 
			//root���� �ڽ��� �� ũ�ٸ� ��ȯ
			if(heap[root] < heap[c] && c < i) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}
	for(int i = 0; i < NUM; i++) {
		printf("%d ", heap[i]);
	}
}

