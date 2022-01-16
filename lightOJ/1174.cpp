#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> bfs(vector<vector<int>>const &g, int src) {
    vector<int> lvl(g.size(), -1);
    queue<int> Q;

    lvl[src] = 0;
    Q.push(src);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        for (int v : g[u]) {
            if (lvl[v] == -1) {
                Q.push(v);
                lvl[v] = lvl[u] + 1;
            }
        }
    }

    return lvl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n, r;
        cin >> n >> r;

        vector<vector<int>> g(n);
        for (int i = 0, u, v; i < r; ++i) {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        int s, e;
        cin >> s >> e;

        vector<int> dis1 = bfs(g, s);
        vector<int> dis2 = bfs(g, e);

        int mx = 0;
        for (int i = 0; i < n; ++i) {
            mx = max(mx, dis1[i] + dis2[i]);
        }

        cout << mx << "\n";
    }

    return 0;
}
