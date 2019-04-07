#include <iostream>
#include <string>

void solve()
{
  std::string N, A, B;
  std::cin >> N;
  for (char c : N) {
    switch (c) {
    case '0':
      A += '0';
      B += '0';
      break;
    case '5':
      A += '2';
      B += '3';
      break;
    default:
      A += '1';
      B += c - 1;
      break;
    }
  }
  while (B.front() == '0') {
    B.erase(B.begin());
  }
  std::cout << A << ' ' << B << '\n';
}

int main()
{
  int T, x = 1;
  for (std::cin >> T; x <= T; x++) {
    std::cout << "Case #" << x << ": ";
    solve();
  }
}
