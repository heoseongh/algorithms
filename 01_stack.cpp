#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();	//���߿� ���� 3�� ������ 
	s.push(4);
	s.pop();
	while(!s. empty()) {
		cout << s.top() << ' ';
		s.pop();	//��� �� pop ���� ����. 
	}
	return 0;
}
