#include <iostream>
#include <algorithm>

using namespace std;

string a[20000];
int n;

int getSum(string a) {
	int length = a.length(), sum = 0;
	for(int i = 0; i < a.length(); i++) {
		// 숫자인 경우에만 더한다.
		// a[i] - '0' ; 아스키 코드를 이해해야함. 
		if(a[i] - '0' >=0 && a[i] - '0' <= 9) {
			sum += a[i] - '0';
		}
	}
	return sum;
} 

bool compare(string a, string b) {
	// 길이가 짧은 순서 우선
	if(a.length() < b.length()) {			// 자신이 더 짧다면 우선순위 높(1) 
		return 1;
	} else if(a.length() > b.length()) {	// 자신이 더 길다면 우선순위 낮(0) 
		return 0;
	}
	// 길이가 같은 경우라면
	else {
		int aSum = getSum(a);
		int bSum = getSum(b);
		// 글자에 포함된 숫자의 합이 다르다면
		if(aSum != bSum) {
			return aSum < bSum;	//작은 합을 가지는 것이 먼저
		} else {
			return a < b;		// 사전 순서대로 
		}
	} 
}

int main(void) {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n, compare);
	for(int i = 0; i < n; i++) {
		cout << a[i] << '\n';
	}
	return 0;
} 
