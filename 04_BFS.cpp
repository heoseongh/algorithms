#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int number = 7;
int v[7]; //방문처리를 위한 배열(checked)
//bool type으로 선언해주면 더 efficient하다.
//c에서는 bool type을 지원하지 x 
 
vector<int> a[8]; //1~7까지 index를 처리해 주기 위한 배열

void bfs(int start) {
	queue<int> q;
	q.push(start);		//Start Node를 큐에 삽입하면서 시작
	v[start] = true;	//시작 노드를 방문 했다는 의미로 'visited'처리
	while(!q.empty()) {
		int x = q.front();	//queue의 front 값을 x로 넘겨주고, 
		q.pop();			//꺼낸뒤 
		printf("%d ", x);	//출력해준다. 
		for(int i = 0; i < a[x].size(); i++) {	//push된 값에 해당하는 노드와 연결된 모든 노드들을 탐색 
			int y = a[x][i];	//a[x]와 연결된 노드의 값을 y에 넣어준다. 
			if(!v[y]) {			//만약 노드에 값이 있다면 
				q.push(y);		//그 노드를 push하고 
				v[y] = true;	//'visited'처리한다. 
			}
		}
	}
}

int main(void) {
	//1과 2를 연결
	a[1].push_back(2);
	a[2].push_back(1);
	//1과 3을 연결 
	a[1].push_back(3);
	a[3].push_back(1);
	//2와 3을 연결 
	a[2].push_back(3);
	a[3].push_back(2);
	//2와 4를 연결 
	a[2].push_back(4);
	a[4].push_back(2);
	//2와 5를 연결 
	a[2].push_back(5);
	a[5].push_back(2);
	//4와 5를 연결 
	a[4].push_back(5);
	a[5].push_back(4);
	//3과 6을 연결 
	a[3].push_back(6);
	a[6].push_back(3);
	//3과 7을 연결
	a[3].push_back(7);
	a[7].push_back(3);
	//6과 7을 연결
	a[6].push_back(7);
	a[7].push_back(6);
	
	bfs(1);	//start-node는 1부터
	
	return 0;
} 
