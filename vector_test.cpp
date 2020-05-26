#include <iostream>
#include <vector>

using namespace std;

vector<int> vec(2);

int main(void) {
	vec[0] = 1;			//vec[0] = 1, size() = 1
	vec[1] = 2;			//vec[1] = 2, size() = 2
	vec[2] = 3;			//vec[2] = 3, size() = 2 
	vec.push_back(4); 	//vec[2] = 4, size() = 3 <- overwrite(3->4)
	vec[3] = 4;			//vec[3] = 4, size() = 3 
	vec[4] = 5;			//vec[4] = 5, size() = 3 <- ��� �ȵ�
	vec.push_back(6);	//vec[3] = 6, size() = 4 <- overwrite(4->6)
	vec.push_back(7);	//vec[4] = 7, size() = 5 <- overwrite(5->7)
	vec.push_back(8);	//vec[5] = 8, size() = 6
	vec[5] = 9;			//vec[5] = 9, size() = 6 <- overwrite(8->9) 
	vec[6] = 10;		//vec[6] = 10, size() = 6 <- ��� �ȵ� 
	vec.resize(10);		//vec[6] ~ vec[9] = 0, size() = 10 <- overwrite(10->0) 
	vec.resize(2);		//vec[0] = 1, vec[1] = 2 ���
	 
	//�迭ó�� �ε����� ���� �����Ͽ� ���� �Է� �� �� ������, 
	//�ᱹ push_back �Լ��� push�� �� �־�� �� size�� �þ�ٴ� ���� �� �� �ִ�.
	//�׸��� resize �Լ��� �� size�� �÷��ִµ� ���� ������ ���� ũ�� �Ҵ��ϸ�
	//�߰��� �Ҵ�� �޸��� ������ 0���� �ʱ�ȭ���ְ�, 
	//���� ������ ���� ������ �� ������ �޸𸮿� �Բ� �������.
	
	for(int i = 0; i < vec.size(); i++){
		cout << "vec[" << i << "] = " << vec[i] << '\n';
	}
}
