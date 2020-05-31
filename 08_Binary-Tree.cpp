#include <iostream>

using namespace std;

int number = 15;	//�� node ����

//�ϳ��� ��� ������ ����ü�� ����
typedef struct node *treePointer;	//node��� ����ü�� treepointer������ �������� ����ϰڴ�. 
typedef struct node {
	int data;
	treePointer leftChild, rightChild;
} node;	//typedef ~ node ; node��� �̸����� ����ϰڴ�.

//���� ��ȸ(Preorder Tracersal) ����
void preorder(treePointer ptr) {
	if(ptr) {	//�����Ͱ� null���� �ƴ϶��
		cout << ptr->data << ' ';	//�ڱ� �ڽ� ���
		preorder(ptr->leftChild);	//���� �ڽ��� ��������� ���
		preorder(ptr->rightChild);	//������ �ڽ��� ��������� ���
	}
}

//���� ��ȸ(Inorder Tracersal) ����
void inorder(treePointer ptr) {
	if(ptr) {	//�����Ͱ� null���� �ƴ϶�� 
		inorder(ptr->leftChild);	//���� �ڽ��� ��������� ���
		cout << ptr->data << ' ';	//�ڱ� �ڽ� ���
		inorder(ptr->rightChild);	//������ �ڽ��� ��������� ���
	}
}

//���� ��ȸ(Postorder Tracersal) ����
void postorder(treePointer ptr) {
	if(ptr) {	//�����Ͱ� null���� �ƴ϶��
		postorder(ptr->leftChild);	//���� �ڽ��� ��������� ���
		postorder(ptr->rightChild);	//������ �ڽ��� ��������� ���
		cout << ptr->data << ' ';	//�ڱ� �ڽ� ���
	}
}

int main(void) {
	node nodes[number + 1];	//15���� node������ ��� �迭 ����(index�� 1���� ����ϱ� ���� +1�� ����) 
	//�� ���Ҹ� �ʱ�ȭ ���ش�. 
	for(int i = 1; i <= number; i++) {
		nodes[i].data = i;				//Data�� 1~15���� ��ȣ�� �ο� 
		nodes[i].leftChild = NULL;		//���� ��� ��� ����x(NULL) ���·� �ʱ�ȭ 
		nodes[i].rightChild = NULL;		//������ ��� ��� ����x(NULL) ���·� �ʱ�ȭ 
	}
	for(int i = 1; i <= number; i++) {
		//¦�� ���� ���ʿ�, Ȧ�� ���� �����ʿ� �־��ش�. 
		if(i % 2 == 0 ) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}
	//���� ��ȸ ��� ��� 
	cout << "preorder  : ";
	preorder(&nodes[1]);
	cout << '\n';
	
	//���� ��ȸ ��� ��� 
	cout << "inorder   : ";
	inorder(&nodes[1]);
	cout << '\n';
	
	//���� ��ȸ ��� ��� 
	cout << "postorder : ";
	postorder(&nodes[1]);
	cout << '\n';
	
	return 0;
}
