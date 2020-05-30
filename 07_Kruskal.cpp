#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

//부모 노드를 찾는 함수 
int getParent(int parent[], int x) {
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

//두 부모 노드를 합치는 함수
int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) parent[b] = a;
	else parent[a] = b;
}

//같은 부모를 가지는지(동일 그래프인지) 확인
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a == b) return 1;	//만약 연결되어 있다면 '1'
	return 0;				//연결되지 않았다면 '0' return
} 
//---------------------------------End<Union-Find>---------------------------------//

//간선 class 선언
class Edge {
public :
	int node[2];	//연결된 두 노드의 정보를 담는 배열
	int distance;	//거리(비용)정보.
	//생성자로 초기화 
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	//정렬 조건 재정의 
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;	//정렬 기준 -> 거리가 작은순  
	}
};
 
int main(void) {
	int n = 5;	//정점의 개수
	int m = 8;	//간선의 개수
	
	vector<Edge> v;	//간선 데이터가 담기는 변수
	v.push_back(Edge(1, 2, 10)); 
	v.push_back(Edge(1, 3, 15));
	v.push_back(Edge(2, 3, 20));
	v.push_back(Edge(2, 4, 16));
	v.push_back(Edge(2, 5, 21));
	v.push_back(Edge(3, 4, 30));
	v.push_back(Edge(3, 5, 11));
	v.push_back(Edge(4, 5, 23));
	
	//간선의 비용을 기준으로 오름차순 정렬
	sort(v.begin(), v.end()); 
	
	//각 정점이 포함된 그래프가 어디인지 저장
	int parent[n];
	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}
	
	int sum = 0;
	for(int i = 0; i < v.size(); i++) {
		if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {	//사이클이 발생하지 않는 경우 
			sum += v[i].distance;										//간선을 추가해주고 
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);	//두 노드를 합쳐줌(=연결해줌, 그래프에 포함)
		}
	}
	printf("%d\n", sum);	
}
