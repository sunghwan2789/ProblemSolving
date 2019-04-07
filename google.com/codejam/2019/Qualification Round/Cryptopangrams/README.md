# Cryptopangrams
  
  
- [x] 10pts
- [ ] 15pts
  
## 문제
  
  
모든 영어 알파벳을 한 번 이상 사용한 문장을 <img src="https://latex.codecogs.com/gif.latex?S"/>라 하자.
<img src="https://latex.codecogs.com/gif.latex?N"/> 보다 작거나 같은 소수 26개를 오름차순으로 선택하고 <img src="https://latex.codecogs.com/gif.latex?P"/>라 하자.
이를 숫자가 작은 순서대로 `A`부터 `Z`까지의 문자로 매핑한다.
  
암호 메시지 <img src="https://latex.codecogs.com/gif.latex?C"/>는 다음 규칙을 따라 구한다.
  
1. <img src="https://latex.codecogs.com/gif.latex?S"/>에서 모든 공백을 제거한다.
2. <img src="https://latex.codecogs.com/gif.latex?C_i%20=%20P[S_i]%20&#x5C;times%20P[S_{i%20+%201}]%20~~%20(단,%200%20&#x5C;leq%20i%20&#x5C;lt%20|S|%20-%201)"/>
  
<img src="https://latex.codecogs.com/gif.latex?C"/>와 <img src="https://latex.codecogs.com/gif.latex?N"/>을 받아 <img src="https://latex.codecogs.com/gif.latex?S"/>를 구하는 프로그램을 작성하시오.
  
## 풀이
  
  
<img src="https://latex.codecogs.com/gif.latex?C_i"/>에서 소수 두 개, 즉, <img src="https://latex.codecogs.com/gif.latex?P[S_i]"/>와 <img src="https://latex.codecogs.com/gif.latex?P[S_{i%20+%201}]"/>를 추출한다.
이 원소들을 중복 없이 오름차순으로 정렬하고, `A`부터 `Z`까지의 문자로 매핑한다.
추출한 순서대로 소수를 문자로 역매핑하면 문제 해결!
  
### 소수 구하기
  
  
[에라토스테네스의 체](https://ko.wikipedia.org/wiki/%EC%97%90%EB%9D%BC%ED%86%A0%EC%8A%A4%ED%85%8C%EB%84%A4%EC%8A%A4%EC%9D%98_%EC%B2%B4 )로 구현하였다.
소수를 어떻게 구하냐가 이 문제의 핵심인 것 같다...
  
### 소수 추출하기
  
  
<img src="https://latex.codecogs.com/gif.latex?C_i%20=%20P[S_i]%20&#x5C;times%20P[S_{i%20+%201}]"/>이면 <img src="https://latex.codecogs.com/gif.latex?C_{i%20+%201}%20=%20P[S_{i%20+%201}]%20&#x5C;times%20P[S_{i%20+%202}]"/>이다.
<img src="https://latex.codecogs.com/gif.latex?P[S_{i%20+%201}]"/>을 가정하는 임의의 소수 <img src="https://latex.codecogs.com/gif.latex?x"/>를 선택하자.
<img src="https://latex.codecogs.com/gif.latex?C_i%20&#x5C;bmod%20x%20=%200"/>이고 <img src="https://latex.codecogs.com/gif.latex?C_{i%20+%201}%20&#x5C;bmod%20x%20=%200"/>이면 <img src="https://latex.codecogs.com/gif.latex?x%20=%20P[S_{i%20+%201}]"/>이다.
  
이 <img src="https://latex.codecogs.com/gif.latex?x"/>를 하나만 구하면, 나머지는 <img src="https://latex.codecogs.com/gif.latex?P[S_{i%20+%202}]%20=%20C_{i%20+%201}%20&#x5C;div%20P[S_{i%20+%201}]"/>이므로 선형 시간에 구할 수 있다.
  
여기서 <img src="https://latex.codecogs.com/gif.latex?C_i%20=%20C_{i%20+%201}"/>이면 <img src="https://latex.codecogs.com/gif.latex?x"/>를 특정할 수 없음에 주의한다.
  
### 중복 없이 오름차순 정렬하기
  
  
C++에는 `std::set<T>`가 있다. 이는 원소를 중복 없이 오름차순 정렬하여 관리하는 컨테이너이므로, 갖다 쓰면 되겠다!!
  
### 소수를 문자로 역매핑하기
  
  
`set`에 소수를 추가한 다음, 추출한 소수 리스트를 순회한다.
이제 `set`에서 각 소수의 순번을 찾고, 해당하는 문자를 `A`부터 매핑한다.
해당하는 코드는 `'A' + std::distance(set.begin(), set.find(i))`가 되겠다.
  