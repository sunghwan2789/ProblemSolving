#include <iostream>
#include <string>

void solve()
{
  int N;
  std::string P, S;
  std::cin >> N >> P;
  for (char c : P) {
    S += c == 'E' ? 'S' : 'E';
  }
  std::cout << S << '\n';
}

int main()
{
  int T, x = 1;
  for (std::cin >> T; x <= T; x++) {
    std::cout << "Case #" << x << ": ";
    solve();
  }
}
