#include <iostream>

using i64 = long long;

constexpr int N = 1e6 + 5;

int from[N];
int to[N];
int belong[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  int n, q;
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    from[i] = to[i] = belong[i] = i;
  }
  while (q--) {
    int opt, a, b;
    std::cin >> opt;
    if (opt == 1) {
      std::cin >> a >> b;
      belong[a] = from[b];
    } else if (opt == 2) {
      std::cin >> a >> b;
      int u = from[a], v = from[b];
      std::swap(to[u], to[v]);
      std::swap(from[a], from[b]);
    } else {
      std::cin >> a;
      std::cout << to[belong[a]] << "\n";
    }
  }
}
