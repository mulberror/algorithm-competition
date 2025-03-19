#include <bits/stdc++.h>

using i64 = long long;

const int N = 15;

int n, m;
i64 ans;
bool vis[N];
std::vector<std::pair<int, i64>> adj[N];

void dfs(int u, i64 s) {
    if (vis[u]) return;
    vis[u] = true;
    if (u == n) {
        ans = std::min(ans, s);
    } else {
        for (auto [v, w]: adj[u]) {
            dfs(v, s ^ w);
        }
    }
    vis[u] = false;
}

int main() {
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v;
        i64 w;
        std::cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    ans = 2e18;
    dfs(1, 0);
    std::cout << ans << "\n";
}