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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);

    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;

        g[u].pb(v);
        g[v].pb(u);
    }

    queue<int> Q;
    vector<int> path(n + 1, -1);

    Q.push(1);
    path[1] = 1;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v : g[u]) {
            if (path[v] == -1) {
                Q.push(v);

                path[v] = u;
            }
        }
    }

    if (path[n] == -1) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        stack<int> stk;
        stk.push(n);

        int u = n;
        while (true) {
            u = path[u];
            stk.push(u);

            if (u == 1) break;
        }
        
        cout << stk.size() << endl;
        while (!stk.empty()) {
            cout << stk.top() << " \n"[stk.size() == 1];
            stk.pop();
        }
    }

    return 0;
}