#include <iostream>
#include <algorithm>

using namespace std;

//정렬할 기준을 마음대로 바꿀 수 있다. 
bool compare(int a, int b){
	return a < b;	//오름차순 정렬을 하겠다. ex a > b : 내림차순. 
}

int main(void){
	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 5};
	sort(a, a + 10, compare);	//stl라이브러리에 있는 sort함수 사용. 
	for(int i = 0; i < 10; i++){
		cout << a[i] << ' ';
	}
}
//sort(a, a + 9)가 아닌 이유
//sort(arr.begin(), arr.end()); 로 사용되곤 하는데
//arr.begin()는 배열의 0번째 인자를 가리키지만, arr.end()는
//배열의 마지막 인자의 다음을 가리킨다.
//이유는 배열 및 컨테이너를 역으로 참조할 때 유용하기 위함이다. 
