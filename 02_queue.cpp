#include <iostream>
#include <queue>

using namespace std;

int main(void) {
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.pop();	//먼저 들어온 1이 삭제됨 
	q.push(4);
	q.pop();
	while(!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
	return 0;
}
