#include <iostream>

void solve()
{
  int o[101] = {};
  for (int i = 0; i < 1000; i++) {
    int n;
    std::cin >> n;
    o[n]++;
  }
  int max = o[0], maxi = 0;
  for (int i = 1; i <= 100; i++) {
    if (max <= o[i]) {
      max = o[i];
      maxi = i;
    }
  }
  std::cout << maxi << "\n";
}

int main()
{
  int T, t;
  for (std::cin >> T; T--;) {
    std::cin >> t;
    std::cout << "#" << t << " ";
    solve();
  }
}
