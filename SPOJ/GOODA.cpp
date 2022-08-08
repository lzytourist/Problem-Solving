#include <iostream>
#include <vector>
#include <bitset>
#include <stack>

using namespace std;

const int N = 1e6;
const int INF = -1e9;

vector<int> g[N], gr[N], components, adj[N];
int roots[N];
long long dist[N], fun[N];
bitset<N> visited;

void dfs(int u, stack<int> &stk) {
    visited[u] = true;

    for (int v: g[u]) {
        if (!visited[v]) {
            dfs(v, stk);
        }
    }

    stk.push(u);
}

void dfs(int u) {
    visited[u] = true;

    components.push_back(u);

    for (int v: gr[u]) {
        if (!visited[v]) {
            dfs(v);
        }
    }
}

void topSort(int u, stack<int> &stk) {
    visited[u] = true;

    for (int v: adj[u]) {
        if (!visited[v]) {
            topSort(v, stk);
        }
    }

    stk.push(u);
}

int main() {
    int n, m, s, e;
    cin >> n >> m >> s >> e;

    --s, --e;

    for (int i = 0; i < n; ++i) {
        cin >> fun[i];

        g[i].clear();
        gr[i].clear();
        roots[i] = i;
        dist[i] = INF;
        visited[i] = false;
    }

    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        --u, --v;

        g[u].push_back(v);
        gr[v].push_back(u);
    }

    stack<int> stk;
    for (int u = 0; u < n; ++u) {
        if (!visited[u]) {
            dfs(u, stk);
        }
    }

    for (int i = 0; i < n; ++i) {
        visited[i] = false;
    }

    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();

        if (!visited[u]) {
            components.clear();

            dfs(u);

            long long root_fun = 0;
            for (int i = 0; i < (int) components.size(); ++i) {
                roots[components[i]] = components.front();
                root_fun += fun[components[i]];
                fun[components[i]] = 0;
            }

            fun[components[0]] = root_fun;
        }
    }

    for (int u = 0; u < n; ++u) {
        for (int const &v: g[u]) {
            if (roots[u] != roots[v]) {
                adj[roots[u]].push_back(roots[v]);
            }
        }
    }

    for (int u = 0; u < n; ++u) {
        visited[u] = false;
    }

    for (int u = 0; u < n; ++u) {
        if (!visited[u] && roots[u] == u) {
            topSort(u, stk);
        }
    }

    dist[roots[s]] = fun[roots[s]];

    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();

        for (int v: adj[u]) {
            if (dist[roots[v]] < dist[roots[u]] + fun[roots[v]]) {
                dist[roots[v]] = dist[roots[u]] + fun[roots[v]];
            }
        }
    }

    cout << dist[roots[e]] << "\n";

    return 0;
}
