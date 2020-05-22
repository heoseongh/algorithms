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
		a[x]++;	//입력될 수의 조건이 자연수이기 때문에 
	}
	for(int i = 0; i < NUM; i++) {
		while(a[i] != 0) {
			printf("%d\n", i);
			a[i]--;
		} 
	}
}

//int a[NUM]; 이와 같이 
//전역변수로 선언해주면
//프로그램 시작과 동시에
//배열의 모든 인덱스의 원소 값 들은 
//'0'으로 초기화됨. 
