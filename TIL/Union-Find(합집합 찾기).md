# Union-Find(합집합 찾기)
 - 대표적인 '그래프'알고리즘
 - *서로소 집합(Disjoint-Set) 알고리즘*이라고도 한다.
 - 여러 노드들 중 두 개의 노드를 선택해서 두 노드가 서로 같은 그래프에 속하는지 아닌지를 판별하는 알고리즘이다.
 - 나중에 Strongly connected component 같은 고급 알고리즘에서도 적용되는 원리이기 때문에 잘 알아두어야 한다.
 
# 과정
### Union(합침)
#### Step.1 모든 노드가 자신을 부모 노드로 갖게 만든다.(초기화)

| index | 1 | 2 | 3 | 4 | 5 |
|:-----:|:-:|:-:|:-:|:-:|:-:|
|parent | 1 | 2 | 3 | 4 | 5 |

```C++
for(int i = 1; i <= 5; i++) {
    parent[i] = i;
	}
```

#### Step.2 만약 1과 2가 연결되었다면, 더 작은 수인 1이 2의 부모가 된다.

| index | 1 | 2 | 3 | 4 | 5 |
|:-----:|:-:|:-:|:-:|:-:|:-:|
|parent | 1 | **1** | 3 | 4 | 5 |

```C++
if(a < b) parent[b] = a;    //a < b, a가 b의 부모가 된다.
    else parent[a] = b;     //b < a, b가 a의 부모가 된다.
```
 - if. 2와 3이 연결되었다면, 더 작은 수인 2가 3의 부모가 된다.
 
| index | 1 | 2 | 3 | 4 | 5 |
|:-----:|:-:|:-:|:-:|:-:|:-:|
|parent | 1 | 1 | **2** | 4 | 5 |

> 여기서 3의 부모는 2이고(parent[3]=2) 2의 부모는 1이므로(parent[2]=1) 결국 3의 부모는 1임을 알 수 있다.(parent[3]=1)  
parent[3]=2, parent[2]=1 ... 이는 재귀함수로 간단하게 표현할 수 있다.
```C++
int getParent(int parent[], int x) {
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}
```
>
| index | 1 | 2 | 3 | 4 | 5 |
|:-----:|:-:|:-:|:-:|:-:|:-:|
|parent | 1 | **1** | **1** | 4 | 5 |

> 결국 3의 부모도 1이 된다.

### Find
> 같은 부모를 가지는지(동일 그래프인지) 확인.
```C++
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);  //a의 부모와
	b = getParent(parent, b);  //b의 부모를 받아서
	if(a == b) return 1;	   //연결되어 있다면 '1'
	return 0;				   //연결되지 않았다면 '0' return
} 
```

# union-find.c
```C
#include <stdio.h>

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

int main(void) {
	int parent[6];
	for(int i = 1; i <= 5; i++) {
		parent[i] = i;
	}
	unionParent(parent, 1, 2);
	unionParent(parent, 2, 3);
	unionParent(parent, 4, 5);
	printf("1과 5는 연결되어 있나요? %d\n", findParent(parent, 1, 5));
}
```
> 결과 : 0
>> 1과 5는 연결되지 않았다.  
= 1과 5는 같은 그래프가 아니다.  
= 1과 5는 합집합이 아니다.  
= 1과 5는 서로소이다.