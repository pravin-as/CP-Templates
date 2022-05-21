// firstly call dfs(1) to set up this code

const ll N = 3e5 + 9, LG = 18;
ll par[N][LG + 1], dep[N], siz[N];
void dfs(ll u, ll p = 0) {
    par[u][0] = p;
    dep[u] = dep[p] + 1;
    siz[u] = 1;
    for (ll i = 1; i <= LG; i++) par[u][i] = par[par[u][i - 1]][i - 1];
    for (auto v: adj[u]) if (v != p) {
        dfs(v, u);
        siz[u] += siz[v];
    }
}
ll lca(ll u, ll v) {
    if (dep[u] < dep[v]) swap(u, v);
    for (ll k = LG; k >= 0; k--) if (dep[par[u][k]] >= dep[v]) u = par[u][k];
    if (u == v) return u;
    for (ll k = LG; k >= 0; k--) if (par[u][k] != par[v][k]) u = par[u][k], v = par[v][k];
    return par[u][0];
}
ll kth(ll u, ll k) {
    assert(k >= 0);
    for (ll i = 0; i <= LG; i++) if (k & (1 << i)) u = par[u][i];
    return u;
}
ll dist(ll u, ll v) {
    ll l = lca(u, v);
    return dep[u] + dep[v] - (dep[l] << 1);
}
//kth node from u to v, 0th node is u
ll go(ll u, ll v, ll k) {
    ll l = lca(u, v);
    ll d = dep[u] + dep[v] - (dep[l] << 1);
    assert(k <= d);
    if (dep[l] + k <= dep[u]) return kth(u, k);
    k -= dep[u] - dep[l];
    return kth(v, dep[v] - dep[l] - k);
}