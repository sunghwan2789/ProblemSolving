#include <iostream>

void solve()
{
  int n = 0, t;
  for (int i = 0; i < 10; i++) {
    std::cin >> t;
    if (t & 1) {
      n += t;
    }
  }
  std::cout << n << "\n";
}

int main()
{
  int T, t = 1;
  for (std::cin >> T; t <= T; t++) {
    std::cout << "#" << t << " ";
    solve();
  }
}
