#include <iostream>
#include <vector>

using namespace std;

int number = 7;
int v[7];
vector<int> a[8];

void dfs(int x) {
	if(v[x]) return;		//�ش� ��带 �湮�ߴٸ�, �Լ��� ������.
	v[x] = true;			//ó���̸� 'visited'ǥ���ϰ� 
	cout << x << ' ';		//��� 
	for(int i = 0; i < a[x].size(); i++) { 
		int y = a[x][i];	//��� �湮�� ����� ������带 ��������
		dfs(y);				//��������� Ž�� 
	} 
}

int main(void) {
	a[1].push_back(2);
	a[2].push_back(1);
	//1�� 3�� ���� 
	a[1].push_back(3);
	a[3].push_back(1);
	//2�� 3�� ���� 
	a[2].push_back(3);
	a[3].push_back(2);
	//2�� 4�� ���� 
	a[2].push_back(4);
	a[4].push_back(2);
	//2�� 5�� ���� 
	a[2].push_back(5);
	a[5].push_back(2);
	//4�� 5�� ���� 
	a[4].push_back(5);
	a[5].push_back(4);
	//3�� 6�� ���� 
	a[3].push_back(6);
	a[6].push_back(3);
	//3�� 7�� ����
	a[3].push_back(7);
	a[7].push_back(3);
	//6�� 7�� ����
	a[6].push_back(7);
	a[7].push_back(6);
	
	dfs(1);
	
	return 0;
} 
