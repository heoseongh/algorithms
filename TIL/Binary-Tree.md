# Binary-Tree(이진트리)
 - 가장 많이 사용되는 비선형 자료구조 중 하나이다.
 - 배열이 아닌 포인터를 사용하여 구현한다.
 > 이 전에 HeapSort를 구현할 때 '완전 이진 트리'를 다루어 보았지만, Tree를 실제로 제대로 구현하기 위해서는 Pointer를 사용해야 한다. Pointer를 사용하면 특정한 Root를 선정하여 그 노드에서 자식 노드로 접근이 간단하게 가능하기 때문에 훨씬 자유롭다.  
   
 > 완전 이진 트리의 경우 배열로 표현이 가능하지만, 일반적인 이진 트리는 배열로 표현하기 어렵기 때문에 Pointer를 사용한다.  
   
 > 만약 일반적인 이진 트리를 배열로 표현한다면 완전 이진 트리의 형태로 만들어주어야 하는데, 그렇게 되면 불필요한 공간마저 생성해 줘야 하므로 메모리의 낭비가 크다.
 
### 탐색 방법
<img src="https://blogfiles.pstatic.net/20160204_169/justkukaro_1454531578896joNlS_PNG/%C6%F7%C8%AD%C0%CC%C1%F8_%C6%AE%B8%AE.png" width="360" height="240">

#### 1. 전위 순회(Preorder Traversal)
```
   i) 자기 자신을 처리  
  ii) 왼쪽 자식 방문  
 iii) 오른쪽 자식 방문
```
```C++
void preorder(treePointer ptr) {
  if(ptr) {                     //포인터가 null값이 아니라면
    cout << ptr->data << ' ';	//자기 자신 출력
    preorder(ptr->leftChild);	//왼쪽 자식을 재귀적으로 출력
    preorder(ptr->rightChild);	//오른쪽 자식을 재귀적으로 출력
  }
}
```
 > 결과 : 1 2 4 8 9 5 10 11 3 6 12 13 7 14 15
 
#### 2. 중위 순회(Indorder Traversal)
```
   i) 왼쪽 자식 방문  
  ii) 먼저 자기 자신을 처리  
 iii) 오른쪽 자식을 방문
```
```C++
void inorder(treePointer ptr) {
  if(ptr) {                     //포인터가 null값이 아니라면
    inorder(ptr->leftChild);    //왼쪽 자식을 재귀적으로 출력
    cout << ptr->data << ' ';   //자기 자신 출력
    inorder(ptr->rightChild);   //오른쪽 자식을 재귀적으로 출력
  }
}
```
 > 결과 : 8 4 9 2 10 5 11 1 12 6 13 3 14 7 15
 
#### 3. 후위 순회(Postorder Traversal)
 - 계산 관련 프로그램을 만들고자 할 때 자주 사용된다.  
 - ex> 계산기가 처리하기 좋은 형태로 데이터를 바꾸고자 할 때, 전위 표기법을 후위 표기법으로 바꾸어라 등.
```
   i) 왼쪽 자식 방문  
  ii) 오른쪽 자식 방문  
 iii) 먼저 자기 자신을 처리
```
```C++
void preorder(treePointer ptr) {
  if(ptr) {                     //포인터가 null값이 아니라면
    preorder(ptr->leftChild);	//왼쪽 자식을 재귀적으로 출력
    preorder(ptr->rightChild);	//오른쪽 자식을 재귀적으로 출력
    cout << ptr->data << ' ';	//자기 자신 출력
  }
}
```
 > 결과 : 8 9 4 10 11 5 2 12 13 6 14 15 7 3 1

# binary-tree.cpp
```C++
#include <iostream>

using namespace std;

int number = 15;	//총 node 개수

//하나의 노드 정보를 구조체로 선언
typedef struct node *treePointer;	//node라는 구조체를 treepointer포인터 형식으로 사용하겠다. 
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;	//typedef ~ node ; node라는 이름으로 사용하겠다.

//전위 순회(Preorder Tracersal) 구현
void preorder(treePointer ptr) {
	if(ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}

//중위 순회(Inorder Tracersal) 구현
void inorder(treePointer ptr) {
	if(ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}

//후위 순회(Postorder Tracersal) 구현
void postorder(treePointer ptr) {
	if(ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}

int main(void) {
	node nodes[number + 1];	//15개의 node정보가 담길 배열 생성(index를 1부터 사용하기 위해 +1을 해줌) 
	//각 원소를 초기화 해준다. 
	for(int i = 1; i <= number; i++) {
		nodes[i].data = i;	        //Data는 1~15까지 번호를 부여 
		nodes[i].leftChild = NULL;	//왼쪽 모든 노드 연결x(NULL) 상태로 초기화 
		nodes[i].rightChild = NULL;	//오른쪽 모든 노드 연결x(NULL) 상태로 초기화 
	}
	for(int i = 1; i <= number; i++) {
		//짝수 값은 왼쪽에, 홀수 값은 오른쪽에 넣어준다. 
		if(i % 2 == 0 ) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}
	//전위 순회 결과 출력 
	cout << "preorder  : ";
	preorder(&nodes[1]);
	cout << '\n';
	
	//중위 순회 결과 출력 
	cout << "inorder   : ";
	inorder(&nodes[1]);
	cout << '\n';
	
	//후위 순회 결과 출력 
	cout << "postorder : ";
	postorder(&nodes[1]);
	cout << '\n';
	
	return 0;
}
```