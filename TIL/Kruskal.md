# Kruskal Algorithm(크루스칼 알고리즘)
 - '최소 비용 신장 트리'를 만들기 위한 대표적인 알고리즘
 - 흔히 여러 개의 도시를 최소한의 비용으로 연결하고자 할 때 실제로 쓰이는 알고리즘이다.
 - **주기적으로 알고리즘 대회에서 출제되는 유형이기 때문에 반드시 잘 알아두어야 한다.**
 - **Union-Find Algorithm이 활용된다.**
 - 노드 = 정점 = 도시
 - 간선 = 거리 = 비용
 - **간선 = 총 노드 - 1**
 - **사이클이 형성되면 안 된다.**
 
# 과정
 > 핵심 : 간선을 거리가 짧은 순서대로 그래프에 포함시킨다.
### Step.1 모든 간선들을 '거리(비용)'을 기준으로 오름차순 정렬한다.
```C++
//정렬 조건 재정의
bool operator <(Edge &edge) {
    return this->distance < edge.distance;	//정렬 기준 -> 거리가 작은순  
}
...
sort(v.begin(), v.end());
```
| a | b | distance |
|:-:|:-:|:--------:|
| 1 | 2 | **10** |
| 3 | 5 | **11** |
| 1 | 3 | **15** |
| 2 | 4 | **16** |
| 2 | 5 | **21** |
| 4 | 5 | **23** |
| 3 | 4 | **30** |

### Step.3 각 정점이 포함된 그래프가 어딘지 저장(Union-Finde Alogrithm 사용하기 위함)
```C++
int parent[n];
    for(int i = 0; i < n; i++) {
        parent[i] = i;
    }
``` 
| node | 1 | 2 | 3 | 4 | 5 |
|:----:|:-:|:-:|:-:|:-:|:-:|
|parent| 1 | 2 | 3 | 4 | 5 |

### Step.2 알고리즘에 맞게 그래프를 연결한다.
> 사이클이 생성되지 않는 경우 간선을 추가하고, 두 노드를 합쳐준다.(=연결해준다, 그래프에 포함시킨다) 
```C++
int sum = 0;
	for(int i = 0; i < v.size(); i++) {
		if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) { //사이클이 발생하지 않는 경우 
			sum += v[i].distance;                                     //간선을 추가해주고 
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);  //두 노드를 합쳐줌(=연결해줌, 그래프에 포함)
		}
	}
```

# kruskal_algorithm.cpp
```C++
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
	if(a == b) return 1;  //만약 연결되어 있다면 '1'
	return 0;   //연결되지 않았다면 '0' return
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
		return this->distance < edge.distance;
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
	
	//오름차순 정렬
	sort(v.begin(), v.end()); 
  
  //각 정점의 그래프 저장
	int parent[n];
	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}
	
	int sum = 0;
	for(int i = 0; i < v.size(); i++) {
		if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].distance;
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}
	printf("%d\n", sum);	
}
```