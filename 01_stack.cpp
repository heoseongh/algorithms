#include <iostream>
#include <stack>

using namespace std;

int main(void) {
	stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.pop();	//나중에 들어온 3이 삭제됨 
	s.push(4);
	s.pop();
	while(!s. empty()) {
		cout << s.top() << ' ';
		s.pop();	//출력 후 pop 잊지 말기. 
	}
	return 0;
}
