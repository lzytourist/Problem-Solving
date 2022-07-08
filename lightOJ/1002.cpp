#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge {
    int u, v, c;

    Edge() = default;

    Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {}

    bool operator<(Edge const &edge) const {
        return edge.c < c;
    }
};

pair<int, int> parent[500];
vector<pair<int, int>> g[500];
int cost[500];

int find_set(int v) {
    if (parent[v].first == v) {
        return v;
    }

    return parent[v].first = find_set(parent[v].first);
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (parent[a].second < parent[b].second) {
            swap(a, b);
        }

        parent[b].first = a;
        parent[a].second += parent[b].second;
    }
}

void dfs(int u, int max_cost) {
    cost[u] = max_cost;

    for (pair<int, int> const &v : g[u]) {
        if (cost[v.first] == -1) {
            dfs(v.first, max(max_cost, v.second));
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ":\n";

        int n, m;
        cin >> n >> m;

        priority_queue<Edge> Q;
        for (int i = 0, u, v, c; i < m; ++i) {
            cin >> u >> v >> c;

            Q.emplace(u, v, c);
        }

        for (int i = 0; i < n; ++i) {
            parent[i] = {i, i};
            g[i].clear();
            cost[i] = -1;
        }

        while (!Q.empty()) {
            Edge edge = Q.top();
            Q.pop();

            if (find_set(edge.u) != find_set(edge.v)) {
                union_set(edge.u, edge.v);

                g[edge.u].emplace_back(edge.v, edge.c);
                g[edge.v].emplace_back(edge.u, edge.c);
            }
        }

        int s;
        cin >> s;

        dfs(s, 0);

        for (int i = 0; i < n; ++i) {
            if (cost[i] == -1) {
                cout << "Impossible\n";
            } else {
                cout << cost[i] << "\n";
            }
        }
    }

    return 0;
}
