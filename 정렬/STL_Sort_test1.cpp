#include <iostream>
#include <algorithm>

using namespace std;

int main(void){
	int arr[5] = {5, 4, 3, 2, 1};
	sort(arr, arr + 5);
	for(int i = 0; i < 10; i++){
		cout << a[i] << ' ';
	}
}
//sort(arr, arr + 4)�� �ƴ� ����
//sort(arr.begin(), arr.end()); �� ���ǰ� �ϴµ�
//arr.begin()�� �迭�� 0��° ���ڸ� ����Ű����, arr.end()��
//�迭�� ������ ������ ������ ����Ų��.
//������ �迭 �� �����̳ʸ� ������ ������ �� �����ϱ� �����̴�. 
