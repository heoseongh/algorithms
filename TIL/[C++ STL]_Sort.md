>### 20년 05월 18일(월)
># C++ STL Sort 사용하기

## STL(Standard Template Library)
 - C++의 일반화된 컨테이너와 그에 상응하는 알고리즘, 반복자와 함수자를 제공.
 - sort 뿐 만 아니라 vector, list, queue, stack, map 등등 지원.
 - #include<algorithm> 선언 해주어야 함.

## Sort()
#### 형식 Sort(첫 주소, 마지막주소)
```C++  
int arr[5] = {5, 4, 3, 2, 1};
sort(arr, arr + 5)
```
#### why? arr + 5
 : 	sort(arr.begin(), arr.end()); 로 사용되곤 하는데
	arr.begin()는 배열의 0번째 인자를 가리키지만,
	arr.end()는 배열의 마지막 인자의 다음을 가리킨다.
	이유는 배열 및 컨테이너를 역으로 참조할 때 유용하기 위함이다. 

## sort()_test1
```C++
int main(void) {
	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 5};
	sort(a, a + 10);
	for(int i = 0; i < 10; i++){
		cout << a[i] << ' ';
	}
}
```
## sort()_test2
```C++
bool compare(int a, int b){
	return a < b;	//오름차순 정렬을 하겠다. ex a > b : 내림차순. 
}
```
```C++
int main(void){
	int a[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 5};
	sort(a, a + 10, compare);
	for(int i = 0; i < 10; i++){
		cout << a[i] << ' ';
	}
}
```
위와 같이 bool 형식의 compare라는 조건을 만들어주고, sort함수의 3번째 인자에 입력해주면
정렬 기준을 입맛대로 수정할 수 있다.

but, 코딩 테스트가 아닌 실무에서는 객체로 정리되어 있는 ‘특정한 변수를 기준으로 정렬’하는 것이 보통이다.
그러므로 아래의 테스트를 수행해본다.

## sort()_test3
```C++
class Student {
public:		//기본적으로 클래스는 기본 접근 지정자가 private이기 때문에 
	string name;
	int score;
	//생성자 
	Student(string name, int score) {
		this->name = name;
		this->score = score;
	}
	//정렬 기준은 '점수가 작은 순서'
	bool operator < (Student &student) {		//오버로딩을 하여 연산자 ‘<’를 재정의 해준다.
		return this->score < student.score;	//default 소팅 기준 : < 
	}						//sort함수 안에 3번째 인자로 <가 생략되어 있다!  
};

int main(void) {
	Student students[] = {
		Student("A", 90),
		Student("B", 100),
		Student("C", 87),
		Student("D", 30),
		Student("E", 93)
	};
	sort(students, students + 5, compare);
	for(int i = 0; i < 5; i++) {
		cout << students[i].name << ' ';
	}
}
```
## 회고
1. test3의 아래 부분을 이해하는데 오래 걸렸다. 연산자 오버로딩과 재 정의에 대해서 확실한 공부가 필요하다.
```C++
bool operator < (Student &student) {
		return this->score < student.score;
}
```
2. 구조체 vs 클래스 / public vs private 차이점 알아둘 것.
- 구조체의 기본 접근한정자 : public
- 클래스의 기본 접근한정자 : private
