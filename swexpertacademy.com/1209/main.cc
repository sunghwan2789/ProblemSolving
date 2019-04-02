#include <iostream>
#include <algorithm>

void solve()
{
  int i, j, sum, max = 0;
  int a[100][100];
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      std::cin >> a[i][j];
    }
  }

  for (i = 0; i < 100; i++) {
    sum = 0;
    for (j = 0; j < 100; j++) {
      sum += a[i][j];
    }
    max = std::max(max, sum);
  }

  for (j = 0; j < 100; j++) {
    sum = 0;
    for (i = 0; i < 100; i++) {
      sum += a[i][j];
    }
    max = std::max(max, sum);
  }

  sum = 0;
  for (i = 0; i < 100; i++) {
    sum += a[i][i];
  }
  max = std::max(max, sum);

  sum = 0;
  for (i = 0, j = 100; i < 100; i++) {
    sum += a[i][--j];
  }
  max = std::max(max, sum);

  std::cout << max << '\n';
}

int main()
{
  for (int T = 10, t; T--;) {
    std::cin >> t;
    std::cout << "#" << t << " ";
    solve();
  }
}
