#include <iostream>
#include <vector>
#include <algorithm>

void solve()
{
  int N;
  std::cin >> N;
  std::vector<int> v(N);
  for (int i = 0; i < N; i++) {
    std::cin >> v[i];
  }

  int s = 0;
  for (int i = 2; i < N; i++) {
    int l = std::max(v[i - 2], v[i - 1]);
    int r = std::max(v[i + 1], v[i + 2]);
    s += std::max(0, v[i] - std::max(l, r));
  }
  std::cout << s << '\n';
}

int main()
{
  for (int t = 1; t <= 10; t++) {
    std::cout << "#" << t << " ";
    solve();
  }
}
