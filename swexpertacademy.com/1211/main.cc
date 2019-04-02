#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

typedef std::tuple<int, int, int> t3;

void solve()
{
  int i, j, w;
  int a[100][100];
  for (i = 0; i < 100; i++) {
    for (j = 0; j < 100; j++) {
      std::cin >> a[i][j];
    }
  }

  std::vector<t3> v;
  for (j = 0; j < 100; j++) {
    if (a[0][j] == 1) {
      v.emplace_back(0, j, j);
    }
  }

  for (i = 99; --i;) {
    for (t3 &t : v) {
      std::tie(w, j, std::ignore) = t;
      if (j > 0 && a[i][j - 1] == 1) {
        while (j > 0 && a[i][j - 1] == 1) {
          j--;
          w++;
        }
      } else {
        while (j < 99 && a[i][j + 1] == 1) {
          j++;
          w++;
        }
      }
      std::get<0>(t) = w;
      std::get<1>(t) = j;
    }
  }

  std::sort(v.begin(), v.end(), [](t3 a, t3 b) {
    if (std::get<0>(a) != std::get<0>(b)) {
      return std::get<0>(a) < std::get<0>(b);
    } else {
      return std::get<2>(a) > std::get<2>(b);
    }
  });

  std::cout << std::get<1>(v.front()) << '\n';
}

int main()
{
  for (int T = 10, t; T--;) {
    std::cin >> t;
    std::cout << "#" << t << " ";
    solve();
  }
}
