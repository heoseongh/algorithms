#include <iostream>
#include <algorithm>

using namespace std;

//������ ������ ������� �ٲ� �� �ִ�. 
bool compare(int a, int b){
	return a < b;	//�������� ������ �ϰڴ�. ex a > b : ��������. 
}

int main(void){
	int arr[5] = {5, 4, 3, 2, 1};
	sort(arr, arr + 5, compare); 
	for(int i = 0; i < 5; i++){
		cout << arr[i] << ' ';
	}
}
