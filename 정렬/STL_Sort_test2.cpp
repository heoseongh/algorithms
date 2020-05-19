#include <iostream>
#include <algorithm>

using namespace std;

//정렬할 기준을 마음대로 바꿀 수 있다. 
bool compare(int a, int b){
	return a < b;	//오름차순 정렬을 하겠다. ex a > b : 내림차순. 
}

int main(void){
	int arr[5] = {5, 4, 3, 2, 1};
	sort(arr, arr + 5, compare); 
	for(int i = 0; i < 5; i++){
		cout << arr[i] << ' ';
	}
}
