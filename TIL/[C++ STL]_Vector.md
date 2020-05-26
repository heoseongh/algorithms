# Vector
 > 사용법
  ```C++
  #include <vector>

  using namespace std;

  //vector 선언
  vector<int> vec1;	//int형 vector 생성
  vector<int> vec2(5);	//크기가 5인 vector 생성(all value = 0)
  vector<int> vec3(vec2); //vec2와 같은 크기인 vector 생성(all value = vec2)

  //vector 값 할당
  vec2[0] = 1		//index 0에 1 할당
  vec.push_back(5)	//끝에 추가로 5 할당

  //vector 값 접근
  for(int i = 0; i < vec2.size(); i++) {
    cout << vec2[i] << ' ';
  }
  ```
 - 런타임 동안 크기 변경이 동적인 배열과 같은 자료구조.
 - 배열과 거의 유사하게 사용 가능.
 - 인덱스 구조를 사용 -> 임의 접근이 가능하고 탐색이 빠르다.
 - 인덱스 구조를 유지해야하기 때문에 삽입/삭제시 비효율적이다.
 - delete[] arr; 처럼 메모리를 해제해줄 필요가 없다.
 - arr.size(), arr.resize() 등 여러가지 함수를 통해 효율적인 메모리 관리 가능

### Vector의 최대 단점은 임의의 자리에 원소 삽입/삭제가 비효율적이다.
 > if 첫 번째 자리의 원소 '1'제거
 >> 제거된 빈 자리로 인해 모든 원소들이 한 칸씩 당겨진다.
 
 >> | 1 | 2 | 3 | 4 | 5 |
 >> |:-:|:-:|:-:|:-:|:-:|
  
 >> | 2 | 3 | 4 | 5 | - |
 >> |:-:|:-:|:-:|:-:|:-:|
 
 > if 첫 번째 자리에 원소 '0'삽입
 >> 모든 원소들이 한 칸씩 뒤로 밀려나면서 삽입된다.
 
 >> | 1 | 2 | 3 | 4 | 5 |
 >> |:-:|:-:|:-:|:-:|:-:|

 >> | 0 | 1 | 2 | 3 | 4 | 5 |
 >> |:-:|:-:|:-:|:-:|:-:|:-:|

### *즉, 삽입/삭제가 빈번하다면 Vector 대신 List를 사용해야 한다.*

# Functions

| 함수          | 설명             |
| :----------- | :--------------- |
| size()       | 원소의 갯수 리턴 |
| resize()     | 크기 변경. 새 크기가 더 클 경우 원래 내용은 유지하고 새로 할당된 모든 원소는 0으로 초기화 |
| capacity(n)  | 할당된 용량 리턴 |
| reserve(n)   | 용량 변경. 새 크기가 더 클 경우 원래 내용은 유지하고 새로 할당된 원소는 초기화하지 않음 |
| empty()      | 원소가 없으면 true 아니면 false를 리턴 |
| clear()      | 모든 원소 삭제 |
| push_back(n) | Vector의 마지막 위치에 원소 삽입 |
| pop_back()   | Vector의 마지막 위치의 원소 제거 |

# Why?
 ### 1. 배열처럼 인덱스를 직접 지정해서 입/출력이 가능할까?
```C++
vector<int> vec(2);

int main(void) {
	vec[0] = 1;			//vec[0] = 1, size() = 2
	vec[1] = 2;			//vec[1] = 2, size() = 2
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << ' ';
	}
}
```
>결과 : 1 2
>>가능하다.

### 2. vec[2]을 추가로 동적할당이 가능할까?
```C++
vec[0] = 1;			//vec[0] = 1, size() = 2
vec[1] = 2;			//vec[1] = 2, size() = 2
vec[2] = 3;			//vec[2] = 2, size() = 2
for(int i = 0; i < vec.size(); i++){
 cout << vec[i] << ' ';
}
```
>결과 : 1 2
>>3이 출력이 안 되었다. 메모리 할당이 제대로 안 된 것인가?
>>for문 조건을 조금 수정해본다.
```C++
for(int i = 0; i < 3; i++)
```
>결과 : 1 2 3
>>3이 출력되는 것으로 보아 메모리가 할당이 되었고 정상적으로 값이 입력되었다. size()가 문제일까?
```C++
cout << vec.size();
```
>결과 : 2
>>size가 그대로 2였기 때문에 for 문이 2번밖에 돌지 않아 출력이 안 되었던 것이다.

### 3. size를 늘리려면?
> 위의 결과를 보면 벡터의 전체적인 사이즈는 초깃값인 2로 고정되어 있다. 이 초깃값을 넉넉하게 확장해놓으려면 **resize()** 함수를,
값을 넣으면서 그때그때 확장하려면 **Push_back**함수를 사용하자.
```C++
vec[0] = 1;       //vec[0] = 1, size() = 2
vec[1] = 2;       //vec[1] = 2, size() = 2
vec.push_back(3)  //vec[2] = 3, size() = 3
for(int i = 0; i < vec.size(); i++){
 cout << vec[i] << ' ';
}
```
>결과 : 1 2 3
>>push_back 함수를 사용해 3을 입력했더니 정상적으로 출력되었다. **전체적인 size가 +1되어 3으로 늘어났기 때문**이다.

### 4. 그럼, 2번 처럼 직접 인덱스를 지정해 값을 입력하고나서 push_back으로 확장하면?
```C++
vec[0] = 1;			   //vec[0] = 1, size() = 2
vec[1] = 2;			   //vec[1] = 2, size() = 2
vec[2] = 3;			   //vec[2] = 2, size() = 2
vec.push_back(4)	//vec[2] = 3, size() = 3
for(int i = 0; i < vec.size(); i++){
 cout << vec[i] << ' ';
}
```
>결과 : 1 2 4
>>vec[2]에는 3이 들어있었는데 4가 출력된다. 벡터의 총 size가 3으로 늘어나면서 push_back(4)의 결과로 덮어씌워지게 된 것.

#### 4.1. 알 수 있는 것.
 - vector에 할당된 메모리를 전부 사용한 경우
 > i) 기존보다 더 큰 메모리를 할당해서 기존의 데이터를 복사하고  
  ii) 이전의 메모리를 삭제한다.  
 iii) 그리고 해당 데이터를 추가하고 인덱스 값을 증가시킨다.
 
 # vector_test.cpp
 ```C++
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
	
	for(int i = 0; i < vec.size(); i++){
		cout << vec[i] << ' ';
	}
}
 ```
 >결과 : 1 2
 >> 배열처럼 인덱스를 직접 지정하여 값을 입력 할 수 있지만, 
 결국 push_back 함수로 push를 해 주어야 총 size가 늘어난다는 것을 알 수 있다.  
	그리고 resize 함수는 총 size를 늘려주는데 기존 사이즈 보다 크게 할당하면
	추가로 할당된 메모리의 값들은 0으로 초기화해주고,
	기존 사이즈 보다 작으면 그 값들은 메모리와 함께 사라진다.