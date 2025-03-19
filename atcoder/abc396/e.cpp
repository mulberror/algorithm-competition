#include <cstring>
#include <iostream>
#include <utility>
#include <vector>

using i64 = long long;

constexpr int N = 2e5 + 5;

int n, m;
std::vector<std::pair<int, int>> adj[N];
int ans[N];

bool vis[N], isok[N];
int cnt[2];
int col[N][2];
bool stat[2];

void dfs(int u, int bit) {
  isok[u] = true;
  cnt[0] += col[u][0];
  cnt[1] += col[u][1];
  for (auto [v, w] : adj[u]) {
    w = w >> bit & 1;
    if (col[v][0] == -1) {
      col[v][0] = col[u][0] ^ w;
      col[v][1] = col[u][1] ^ w;
      dfs(v, bit);
    } else {
      if (col[v][0] != (col[u][0] ^ w)) {
        stat[0] = false;
      }
      if (col[v][1] != (col[u][1] ^ w)) {
        stat[1] = false;
      }
    }
  }
}

void copy(int u, int op, int bit) {
  if (vis[u]) {
    return;
  }
  isok[u] = true;
  ans[u] += (op << bit);
  vis[u] = true;
  for (auto [v, w] : adj[u]) {
    w = w >> bit & 1;
    copy(v, op ^ w, bit);
  }
}

void clear(int u) {
  col[u][0] = col[u][1] = -1;
  vis[u] = false;
  for (auto [v, w] : adj[u]) {
    if (col[v][0] != -1 || col[v][1] != -1 || vis[v]) {
      clear(v);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  for (int i = 1; i <= n; i++) {
    if (!isok[i]) {
      for (int bit = 0; bit < 30; bit++) {
        cnt[0] = cnt[1] = 0;
        stat[0] = stat[1] = true;
        clear(i);
        col[i][0] = 0, col[i][1] = 1;
        dfs(i, bit);
        if (!stat[0] && !stat[1]) {
          std::cout << "-1\n";
          return 0;
        }
        if (!stat[0] || (cnt[1] < cnt[0])) {
          copy(i, 1, bit);
        } else {
          copy(i, 0, bit);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << ans[i] << " \n"[i == n];
  }
}
