#include <iostream>
#include <algorithm>

using namespace std;

//������ ������ ������� �ٲ� �� �ִ�. 
bool compare(int a, int b){
	return a < b;	//�������� ������ �ϰڴ�. ex a > b : ��������. 
}

int main(void){
	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 5};
	sort(a, a + 10, compare);	//stl���̺귯���� �ִ� sort�Լ� ���. 
	for(int i = 0; i < 10; i++){
		cout << a[i] << ' ';
	}
}
//sort(a, a + 9)�� �ƴ� ����
//sort(arr.begin(), arr.end()); �� ���ǰ� �ϴµ�
//arr.begin()�� �迭�� 0��° ���ڸ� ����Ű����, arr.end()��
//�迭�� ������ ������ ������ ����Ų��.
//������ �迭 �� �����̳ʸ� ������ ������ �� �����ϱ� �����̴�. 
