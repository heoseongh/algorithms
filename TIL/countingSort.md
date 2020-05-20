# Counting Sort?
- 크기를 기준으로 개수를 count 하는 알고리즘
- 범위 조건이 있는 경우에 한해서는 가장 빠르다.
- T(n) = O(N)
## 과정
#### 1) 카운트할 배열 선언
```C++
int count[3]; 
```
#### 2) 배열에 값을 넣는다.
```C++
int array[20] = { 
		1, 2, 2, 1, 3, 
		1, 3, 3, 2, 1, 
		1, 2, 2, 1, 3, 
		2, 1, 3, 3, 3
	}
```
#### 3) count 배열 초기화
```C++
for(int i = 0; i < 3; i++) {
		count[i] = 0;
	}
```

| 크기 = 1 | 크기 = 2 | 크기 = 3 |
| :------: | :------: | :------: |
|     0    |    0     |     0    |
| count[0] | count[1] | count[2] |

#### 4) 배열을 돌리면서 해당하는 크기의 수를 count한다.
```C++
	for(int i = 0; i <20; i++) {
		count[array[i] - 1]++;   
  }                         
```
> 1을 만나면 -> count[0]++  
> 2를 만나면 -> count[1]++  
> 3을 만나면 -> count[2]++

| 크기 = 1 | 크기 = 2 | 크기 = 3 |
| :------: | :------: | :------: |
|     7    |    6     |     7    |
| count[0] | count[1] | count[2] |

#### 5) count된 갯수만큼 차례대로 출력한다.
```C++
for(int i = 0; i < 3; i++) {
		if(count[i] != 0) {
			for(int j = 0; j < count[i]; j++) {
				printf("%d", i + 1);
			}
		}
	}
```
>**결과** : 1111111 222222 3333333

# counting_Sort.cpp
```C++
#include <stdio.h>
#define NUM 3
int main(void) {
	int temp;
	int count[3]; 
	int array[20] = { 
		1, 2, 2, 1, 3, 
		1, 3, 3, 2, 1, 
		1, 2, 2, 1, 3, 
		2, 1, 3, 3, 3
	}
	//배열 초기화 
	for(int i = 0; i < NUM; i++) {
		count[i] = 0;
	}
	for(int i = 0; i <20; i++) {
		count[array[i] - 1]++;
	} 
	for(int i = 0; i < NUM; i++) {
		if(count[i] != 0) {
			for(int j = 0; j < count[i]; j++) {
				printf("%d", i + 1);
			}
		}
	}

	return 0;
}

```
