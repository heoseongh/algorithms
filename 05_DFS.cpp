#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int v[7];
vector<int> a[8];

void dfs(int x) {
	if(v[x]) return;		//해당 노드를 방문했다면, 함수를 끝내라.
	v[x] = true;			//처음이면 'visited'표시하고 
	cout << x << ' ';		//출력 
	for(int i = 0; i < a[x].size(); i++) { 
		int y = a[x][i];	//방금 방문한 노드의 인접노드를 기준으로
		dfs(y);				//재귀적으로 탐색 
	} 
}

int main(void) {
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
	
	dfs(1);
	
	return 0;
} 
