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
	if(ptr) {	//포인터가 null값이 아니라면
		cout << ptr->data << ' ';	//자기 자신 출력
		preorder(ptr->leftChild);	//왼쪽 자식을 재귀적으로 출력
		preorder(ptr->rightChild);	//오른쪽 자식을 재귀적으로 출력
	}
}

//중위 순회(Inorder Tracersal) 구현
void inorder(treePointer ptr) {
	if(ptr) {	//포인터가 null값이 아니라면 
		inorder(ptr->leftChild);	//왼쪽 자식을 재귀적으로 출력
		cout << ptr->data << ' ';	//자기 자신 출력
		inorder(ptr->rightChild);	//오른쪽 자식을 재귀적으로 출력
	}
}

//후위 순회(Postorder Tracersal) 구현
void postorder(treePointer ptr) {
	if(ptr) {	//포인터가 null값이 아니라면
		postorder(ptr->leftChild);	//왼쪽 자식을 재귀적으로 출력
		postorder(ptr->rightChild);	//오른쪽 자식을 재귀적으로 출력
		cout << ptr->data << ' ';	//자기 자신 출력
	}
}

int main(void) {
	node nodes[number + 1];	//15개의 node정보가 담길 배열 생성(index를 1부터 사용하기 위해 +1을 해줌) 
	//각 원소를 초기화 해준다. 
	for(int i = 1; i <= number; i++) {
		nodes[i].data = i;				//Data는 1~15까지 번호를 부여 
		nodes[i].leftChild = NULL;		//왼쪽 모든 노드 연결x(NULL) 상태로 초기화 
		nodes[i].rightChild = NULL;		//오른쪽 모든 노드 연결x(NULL) 상태로 초기화 
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
