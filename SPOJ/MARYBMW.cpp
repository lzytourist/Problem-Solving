#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>
#include <bitset>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Edge {
    int u, v;
    ll c;
    
    Edge() = default;
    
    Edge(int _u, int _v, ll _c) : u(_u), v(_v), c(_c) {}
    
    bool operator<(Edge const &edge) const {
        return c < edge.c;
    }
};

int n, m;
pair<int, int> parent[50000];
vector<pair<int, ll>> g[50000];
bitset<50000> vis;

int find_set(int v) {
    if (parent[v].F == v) {
        return v;
    }
    
    return parent[v].F = find_set(parent[v].F);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    
    if (a != b) {
        if (parent[a].S < parent[b].S) {
            swap(a, b);
        }
        
        parent[b].F = a;
        parent[a].S += parent[b].S;
    }
}

ll ans;

void dfs(int u, ll cost) {
    vis[u] = 1;
    
    if (u == n - 1) {
        ans = cost;
        return;
    }
    
    for (pair<int, ll> const &v : g[u]) {
        if (!vis[v.F]) {
            dfs(v.F, min(cost, v.S));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n >> m;
        
        for (int i = 0; i < n; ++i) {
            parent[i] = {i, 1};
            g[i].clear();
            vis[i] = 0;
        }
        
        priority_queue<Edge> Q;
        for (int i = 0, u, v; i < 1LL * m; ++i) {
            ll c;
            cin >> u >> v >> c;
            --u, --v;
            
            Q.push(Edge(u, v, c));
        }
        
        
        while (!Q.empty()) {
            Edge edge = Q.top();
            Q.pop();
            
            if (find_set(edge.u) != find_set(edge.v)) {
                union_set(edge.u, edge.v);
                
                g[edge.u].pb({edge.v, edge.c});
                g[edge.v].pb({edge.u, edge.c});
            }
        }
        
        ans = -1;
        dfs(0, 1e18);
        
        cout << ans << endl;
    }
    
    return 0;
}
