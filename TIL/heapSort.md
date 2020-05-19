# Heap Sort?
- Heap을 이용한 정렬 알고리즘.
- Max heap Tree / Min heap Tree를 구성해 정렬을 하는 방법이다.  
    i. 내림차순 정렬을 위해서는 Max heap  
    ii. 오름차순 정렬을 위해서는 Min heap
- 과정  
  1) **heapfiy algorithm**을 이용해 Data를 완전 이진트리 형태(Max heap -> 내림차순)로 만든다.  
  2) root와 마지막 노드를 Swap한다.(이 때 마지막 노드는 가장 큰 노드가 되며 정렬이 완료된다.)
  3) **heapfiy algorithm**을 이용해 내림차순으로 재정렬한다.
  4) 정렬이 완료된 노드를 제외한 이진트리에서 root와 마지막 노드를 Swap한다.(그럼 최하단의 두 노드는 정렬이 완료 된 것이다.)
  5) 3)과 4)를 반복한다.
  
- QuickSort와 MergeSort만큼 빠르다.
- 시간복잡도 T(n) = O(nlogn)
- 고급 프로그래밍 기법으로 갈수록 Heap의 개념이 자주 등장하기 때문에 중요하다.

# Heap?
>## 선행 개념
>>### 1. Binary Tree(이진트리)?
- 데이터를 각 노드에 담은 뒤에 노드를 두 개씩 이어 붙이는 구조.
- 부모 -> 자식 으로 뻗어나감
- 모든 노드의 자식노드 <= 2
- 트리의 최상부 : Root-node
- 트리의 최하단 : Leaf-node

>>### 2. Complete Binary Tree(완전이진트리)?
- 왼쪽 부분부터 오른쪽 부분까지 차근차근 중간에 비는 데이터 없이 완전하게 차있는 트리.

>## Heap
- 최솟값/최댓값을 빠르게 찾아내기 위해 완전 이진 트리를 기반으로 하는 트리 
- Max heap : 부모 노드 > 자식 노드 (더 큰 값이 부모가 된다)
- Min heap : 부모 노드 < 자식 노드 (더 작은 값이 부모가 된다.)
> 힙 생성 알고리즘(Heapify Algorithm)
> 특정 노드의 두 자식 중에서 더 큰 자식과 자신의 위치를 바꾸는 알고리즘이다.
> 특정 노드 때문에 힙이 붕괴되는 경우 사용한다.

## Heapify algorithm
```C++
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
```

# heap_Sort.cpp
```C++
#include <stdio.h>
#define NUM 6

int heap[NUM] = {5, 4, 3, 3, 2, 1};

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
```
