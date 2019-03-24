#include <iostream>
#include <algorithm>

void solve()
{
  int dump;
  int v[100];
  std::cin >> dump;
  for (int i = 0; i < 100; i++) {
    std::cin >> v[i];
  }
  std::sort(v, v + 100);
  int &max = v[99], &min = v[0];
  for (int i = 0; i < dump; i++) {
    int p = --max, a = 99;
    for (; a > 0 && v[a - 1] > p; a--) {
      v[a] = v[a - 1];
    }
    v[a] = p;

    int q = ++min, b = 0;
    for (; b < 99 && v[b + 1] < q; b++) {
      v[b] = v[b + 1];
    }
    v[b] = q;
  }
  std::cout << max - min << "\n";
}

int main()
{
  for (int T = 1; T <= 10; T++) {
    std::cout << "#" << T << " ";
    solve();
  }
}
