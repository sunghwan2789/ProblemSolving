#include <iostream>

void solve()
{
  int i, j, d, s;
  int a[100][100];
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      std::cin >> a[i][j];
    }
  }

  for (j = 0; j < 100; j++) {
    if (a[99][j] == 2) {
      d = j;
      break;
    }
  }

  j = d;
  for (i = 99; --i;) {
    if (j > 0 && a[i][j - 1] == 1) {
      while (j > 0 && a[i][j - 1] == 1) {
        j--;
      }
    } else {
      while (j < 99 && a[i][j + 1] == 1) {
        j++;
      }
    }
  }
  s = j;

  std::cout << s << '\n';
}

int main()
{
  for (int T = 10, t; T--;) {
    std::cin >> t;
    std::cout << "#" << t << " ";
    solve();
  }
}
