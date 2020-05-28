# DFS(Depth First Search, 깊이 우선 탐색)
 - 깊이를 우선으로 하여 탐색을 수행하는 탐색 알고리즘
 - '맹목적 탐색'을 하고자 할 때 사용할 수 있는 탐색 기법
 - BFS에서는 큐(Queue)가 사용되었다면 DFS에서는 스택(Stack)이 사용된다.
 - 사실 스택을 사용하지 않아도 단순히 **재귀 함수만 이용해도 구현이 가능하다.**
 - Computer는 구조적으로 항상 Stack의 원리를 사용하기 때문.
 - 프로그래밍 대회에서는 재귀함수 형식으로 코딩하는 것이 더 빠르다.
 > DFS 또한 그 자체로는 큰 의미가 없지만 DFS를 활용해서 문제를 해결해야 할 경우가 많기 때문에 정확한 작동 원리를 아는 것이 중요!
 
# 과정
### 1~7까지 max heap tree 라고 가정
1. Start Node를 스택에 삽입하면서 시작
2. 시작 노드를 방문 했다는 의미로 'visited'처리
3. 그 후부터는 일련의 알고리즘에 따라 동작한다.  
   i) 스택의 top 노드를 확인한다.  
  ii) top 노드를 기준으로 방문하지 않은 인접 노드가 있으면, 그 노드를 스택에 넣고 'visited'처리.  
 iii)더이상 방문하지 않은 인접 노드가 없으면 top을 push한다.  
 
# dfs_재귀함수사용.cpp
```C++
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
```