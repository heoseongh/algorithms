# 자료구조
 - 데이터를 필요에 따라 분류 해 놓은 것
 - 상황에 맞는 자료구조를 사용하면 더 효율적으로 관리가 가능
 - 실행시간과 메모리 용량을 줄일 수 있다.

### 종류
 - 선형 구조 : List, Stack, Queue, Deque
 - 비선형 구조 : Tree, Graph

# 1. Stack
 > 나중에 들어간 것이 먼저 나온다(LIFO)
  - Push() : item In
  - Pop() : item Out
  - Top() : Last In item

```C++
  #include <iostream>
  #include <stack>

  using namespace std;

  int main(void) {
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.pop();	//나중에 들어온 3이 삭제됨 
    s.push(4);
    s.pop();
    while(!s. empty()) {
      cout << s.top() << ' ';
      s.pop();	//출력 후 pop 잊지 말기
    }
    return 0;
  }
```

# 2. Queue
 > 먼저 들어간 것이 먼저 나온다(FIFO)  
  - Push() : item In
  - Pop() : item Out
  - Front() : First In item
  
```C++
  #include <iostream>
  #include <queue>

  using namespace std;

  int main(void) {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();	//먼저 들어온 1이 삭제됨 
    q.push(4);
    q.pop();
    while(!q.empty()) {
      cout << q.front() << ' ';
      q.pop();
    }
    return 0;
  }
```
