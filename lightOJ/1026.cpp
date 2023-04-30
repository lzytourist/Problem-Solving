#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<typename T>
void scan(vector<T> &v) {for (T &x : v) cin >> x;}

const int N = 10000;
vector<int> adj[N];
int low[N], disc[N], timer;
bitset<N> vis;
vector<pair<int, int>> critical;

void dfs(int u, int p) {
    vis[u] = true;
    disc[u] = low[u] = ++timer;

    for (int v : adj[u]) {
        if (v == p) continue;

        if (!vis[v]) {
            dfs(v, u);

            low[u] = min(low[u], low[v]);

            if (low[v] > disc[u]) {
                critical.emplace_back(min(u, v), max(u, v));
            }
        } else {
            low[u] = min(low[u], disc[v]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LUCHADOR
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ":\n";

        int n;
        cin >> n;

        for (int i = 0; i < n; ++i) {
            disc[i] = low[i] = INT_MAX;
            vis[i] = false;
        }

        char c;
        for (int i = 0, u, k; i < n; ++i) {
            cin >> u >> c >> k >> c;

            adj[u].resize(k);
            scan(adj[u]);
        }

        timer = 0;
        critical.clear();
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                dfs(i, -1);
            }
        }

        cout << critical.size() << " critical links" << endl;

        sort(critical.begin(), critical.end());
        for (auto &[u, v] : critical) {
            cout << u << " - " << v << endl;
        }
    }

    return 0;
}