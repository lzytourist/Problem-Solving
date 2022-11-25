#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template <typename T>
void scan(vector<T> &v) {for(T &x : v) {cin >> x;}}

const int N = 1e5;

bitset<N> vis;
vector<int> g[N];
int n, m;

void dfs(int u) {
    vis[u] = true;

    for (int const &v : g[u]) {
        if (!vis[v]) {
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        --u, --v;

        g[u].pb(v);
        g[v].pb(u);
    }

    stack<int> stk;
    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            stk.push(i);
            dfs(i);
        }
    }

    cout << stk.size() - 1 << endl;
    int u = stk.top();
    stk.pop();

    while (!stk.empty()) {
        cout << stk.top() + 1 << " " << u + 1 << endl;
        stk.pop();
    }

    return 0;
}