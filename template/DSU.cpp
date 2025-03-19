struct DSU {
  std::vector<int> fa, siz;
  int n;

  DSU(int n) : n(n + 1), fa(n + 1), siz(n + 1) {
    std::iota(fa.begin(), fa.end(), 0);
    std::fill(siz.begin(), siz.end(), 1);
  }

  int leader(int u) { return fa[u] == u ? fa[u] : fa[u] = leader(fa[u]); }

  bool merge(int u, int v) {
    u = leader(u), v = leader(v);
    if (u != v) {
      fa[u] = v;
      siz[v] += siz[u];
    }
  }

  bool same(int u, int v) { return leader(u) == leader(v); }
};
