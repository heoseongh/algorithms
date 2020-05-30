#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

//�θ� ��带 ã�� �Լ� 
int getParent(int parent[], int x) {
	if(parent[x] == x) return x;
	return parent[x] = getParent(parent, parent[x]);
}

//�� �θ� ��带 ��ġ�� �Լ�
int unionParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a < b) parent[b] = a;
	else parent[a] = b;
}

//���� �θ� ��������(���� �׷�������) Ȯ��
int findParent(int parent[], int a, int b) {
	a = getParent(parent, a);
	b = getParent(parent, b);
	if(a == b) return 1;	//���� ����Ǿ� �ִٸ� '1'
	return 0;				//������� �ʾҴٸ� '0' return
} 
//---------------------------------End<Union-Find>---------------------------------//

//���� class ����
class Edge {
public :
	int node[2];	//����� �� ����� ������ ��� �迭
	int distance;	//�Ÿ�(���)����.
	//�����ڷ� �ʱ�ȭ 
	Edge(int a, int b, int distance) {
		this->node[0] = a;
		this->node[1] = b;
		this->distance = distance;
	}
	//���� ���� ������ 
	bool operator <(Edge &edge) {
		return this->distance < edge.distance;	//���� ���� -> �Ÿ��� ������  
	}
};
 
int main(void) {
	int n = 5;	//������ ����
	int m = 8;	//������ ����
	
	vector<Edge> v;	//���� �����Ͱ� ���� ����
	v.push_back(Edge(1, 2, 10)); 
	v.push_back(Edge(1, 3, 15));
	v.push_back(Edge(2, 3, 20));
	v.push_back(Edge(2, 4, 16));
	v.push_back(Edge(2, 5, 21));
	v.push_back(Edge(3, 4, 30));
	v.push_back(Edge(3, 5, 11));
	v.push_back(Edge(4, 5, 23));
	
	//������ ����� �������� �������� ����
	sort(v.begin(), v.end()); 
	
	//�� ������ ���Ե� �׷����� ������� ����
	int parent[n];
	for(int i = 0; i < n; i++) {
		parent[i] = i;
	}
	
	int sum = 0;
	for(int i = 0; i < v.size(); i++) {
		if(!findParent(parent, v[i].node[0] - 1, v[i].node[1] - 1)) {	//����Ŭ�� �߻����� �ʴ� ��� 
			sum += v[i].distance;										//������ �߰����ְ� 
			unionParent(parent, v[i].node[0] - 1, v[i].node[1] - 1);	//�� ��带 ������(=��������, �׷����� ����)
		}
	}
	printf("%d\n", sum);	
}
