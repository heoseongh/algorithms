#include <iostream>
#include <vector>

using namespace std;

vector<int> vec(2);

int main(void) {
	vec[0] = 1;			//vec[0] = 1, size() = 1
	vec[1] = 2;			//vec[1] = 2, size() = 2
	vec[2] = 3;			//vec[2] = 3, size() = 2 
	vec.push_back(4); 	//vec[2] = 4, size() = 3 <- overwrite(3->4)
	vec[3] = 4;			//vec[3] = 4, size() = 3 
	vec[4] = 5;			//vec[4] = 5, size() = 3 <- 출력 안됨
	vec.push_back(6);	//vec[3] = 6, size() = 4 <- overwrite(4->6)
	vec.push_back(7);	//vec[4] = 7, size() = 5 <- overwrite(5->7)
	vec.push_back(8);	//vec[5] = 8, size() = 6
	vec[5] = 9;			//vec[5] = 9, size() = 6 <- overwrite(8->9) 
	vec[6] = 10;		//vec[6] = 10, size() = 6 <- 출력 안됨 
	vec.resize(10);		//vec[6] ~ vec[9] = 0, size() = 10 <- overwrite(10->0) 
	vec.resize(2);		//vec[0] = 1, vec[1] = 2 출력
	 
	//배열처럼 인덱스를 직접 지정하여 값을 입력 할 수 있지만, 
	//결국 push_back 함수로 push를 해 주어야 총 size가 늘어난다는 것을 알 수 있다.
	//그리고 resize 함수는 총 size를 늘려주는데 기존 사이즈 보다 크게 할당하면
	//추가로 할당된 메모리의 값들은 0으로 초기화해주고, 
	//기존 사이즈 보다 작으면 그 값들은 메모리와 함께 사라진다.
	
	for(int i = 0; i < vec.size(); i++){
		cout << "vec[" << i << "] = " << vec[i] << '\n';
	}
}
