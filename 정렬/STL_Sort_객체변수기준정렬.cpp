#include <iostream>
#include <algorithm>

using namespace std;

class Student{
public:		//기본적으로 클래스는 기본 접근 지정자가 private이기 때문에 
	string name;
	int score;
	//생성자 
	Student(string name, int score){
		this->name = name;
		this->score = score;
	}
	//정렬 기준은 '점수가 작은 순서'
	bool operator < (Student &student){		//오버로딩을 하여 연산자< 를 재정의 해준다
		return this->score < student.score;	//default 소팅 기준 : < 
	}										//sort함수 안에 3번째 인자로 <가 생략되어 있다!  
};

int main(void){
	Student students[] = {
		Student("A", 90),
		Student("B", 100),
		Student("C", 87),
		Student("D", 30),
		Student("E", 93)
	};
	sort(students, students + 5);
	for(int i = 0; i < 5; i++){
		cout << students[i].name << ' ';
	}
}
	
	
