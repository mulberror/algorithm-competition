#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 5;

int n, m;
int U[N], V[N], W[N];
std::vector<std::pair<int, int>> 
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        std::cin >> U[i] >> V[i] >> W[i];
        adj[U[i]].push_back({V[i], W[i]});
        adj[V[i]].push_back({U[i], W[i]});
    }
}