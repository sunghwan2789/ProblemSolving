#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

std::vector<int> prime(int n)
{
  std::vector<int> p = { 2 };
  std::vector<bool> s(n + 1, false);
  for (int i = 3; i <= n; i += 2) {
    if (!s[i]) {
      p.push_back(i);
      for (int j = i * i; j <= n; j += i) {
        s[j] = true;
      }
    }
  }
  return p;
}

std::vector<int> p = prime(10000);

int extract(int a, int b) {
  int x, y;
  for (int i : p) {
    if (a % i == 0) {
      x = i;
      y = a / x;
      if (b % y != 0) {
        std::swap(x, y);
      }
      return x;
    }
  }
  return -1;
}

void solve()
{
  int N, L;
  std::cin >> N >> L;
  std::vector<int> cipher(L);
  for (int i = 0; i < L; i++) {
    std::cin >> cipher[i];
  }

  std::vector<int> primes;
  for (int i = 1; i < L; i++) {
    if (cipher[i - 1] != cipher[i]) {
      int a = extract(cipher[i - 1], cipher[i]);
      for (; i > 1; i--) {
        a = cipher[i - 1] / a;
      }
      primes.push_back(a);
      break;
    }
  }
  for (int i = 0; i < L; i++) {
    primes.push_back(cipher[i] / primes[i]);
  }
  std::set<int> index(primes.begin(), primes.end());

  std::string plain;
  for (int i : primes) {
    plain += 'A' + std::distance(index.begin(), index.find(i));
  }
  std::cout << plain << '\n';
}

int main()
{
  int T, x = 1;
  for (std::cin >> T; x <= T; x++) {
    std::cout << "Case #" << x << ": ";
    solve();
  }
}
