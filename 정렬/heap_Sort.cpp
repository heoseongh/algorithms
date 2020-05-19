#include <stdio.h>
#define NUM 9

int heap[NUM] = {7, 6, 5, 8, 3, 5, 9, 1, 6};

int main(void) {
	//전체 트리 구조를 최대 힙 구조로 만들기
	//Heapify algorithm O(logn) 
	for(int i = 1; i < NUM; i++) {
		int c = i;
		do {
			int root = (c - 1) / 2;		//Child-Node - 1 / 2 = Parent-Node
			if(heap[root] < heap[c]) {	//'부모노드 < 자식노드'이면 Swap 
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			c = root;
		} while (c != 0);
	}
	//크기를 줄여가며 반복적으로 힙을 구성.
	for(int i = NUM - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;

		//Heapify algorithm O(logn)
		do {
			c = 2 * root + 1;
			//자식 중 더 큰 값 찾기
			if(heap[c] < heap[c + 1] && c < (i - 1)) {
				c++;
			} 
			//root보다 자식이 더 크다면 교환
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

