#include <iostream>
#include <algorithm>

using namespace std;

class Student{
public:		//�⺻������ Ŭ������ �⺻ ���� �����ڰ� private�̱� ������ 
	string name;
	int score;
	//������ 
	Student(string name, int score){
		this->name = name;
		this->score = score;
	}
	//���� ������ '������ ���� ����'
	bool operator < (Student &student){		//�����ε��� �Ͽ� ������< �� ������ ���ش�
		return this->score < student.score;	//default ���� ���� : < 
	}										//sort�Լ� �ȿ� 3��° ���ڷ� <�� �����Ǿ� �ִ�!  
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
	
	
