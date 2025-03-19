#include <iostream>
#include <queue>
#include <vector>

using i64 = long long;

constexpr int N = 4e5 + 5;
constexpr i64 INF = 1e18;

int n, m, cost;
std::vector<std::pair<int, int>> adj[N];
i64 dist[N];
bool vis[N];

struct Node {
  int u;
  i64 dis;
  bool operator<(const Node &rhs) const { return dis > rhs.dis; }
};

void spfa(int s) {
  for (int i = 1; i <= 2 * n; i++) {
    dist[i] = INF;
    vis[i] = false;
  }
  dist[s] = 0;
  std::priority_queue<Node> q;
  q.push({s, 0});
  while (!q.empty()) {
    auto [u, _] = q.top();
    q.pop();
    if (vis[u]) {
      continue;
    }
    vis[u] = true;
    for (auto [v, w] : adj[u]) {
      if (dist[v] > dist[u] + w) {
        dist[v] = std::min(dist[v], dist[u] + w);
        q.push({v, dist[v]});
      }
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  std::cin >> n >> m >> cost;
  for (int i = 1; i <= n; i++) {
    adj[i].push_back({i + n, cost});
    adj[i + n].push_back({i, cost});
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back({v, 1});
    adj[v + n].push_back({u + n, 1});
  }
  spfa(1);
  std::cout << std::min(dist[n], dist[n * 2]) << "\n";
}
