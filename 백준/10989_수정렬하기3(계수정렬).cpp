#include <iostream>
#define NUM 10001

using namespace std;

int n;
int a[NUM];

int main(void) {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		int x;
		scanf("%d", &x);
		a[x]++;	//�Էµ� ���� ������ �ڿ����̱� ������ 
	}
	for(int i = 0; i < NUM; i++) {
		while(a[i] != 0) {
			printf("%d\n", i);
			a[i]--;
		} 
	}
}

//int a[NUM]; �̿� ���� 
//���������� �������ָ�
//���α׷� ���۰� ���ÿ�
//�迭�� ��� �ε����� ���� �� ���� 
//'0'���� �ʱ�ȭ��. 
