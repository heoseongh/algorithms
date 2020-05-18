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
//sort(arr, arr + 4)가 아닌 이유
//sort(arr.begin(), arr.end()); 로 사용되곤 하는데
//arr.begin()는 배열의 0번째 인자를 가리키지만, arr.end()는
//배열의 마지막 인자의 다음을 가리킨다.
//이유는 배열 및 컨테이너를 역으로 참조할 때 유용하기 위함이다. 
