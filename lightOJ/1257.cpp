#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Node {
    int node, cost;

    Node() = default;

    Node(int _node, int _cost) {
        node = _node;
        cost = _cost;
    }
};

pair<int, vector<int>> get_farthest(vector<vector<Node>> const &g, int src) {
    pair<int, int> farthest = {src, 0};
    queue<int> Q;
    vector<int> distance(g.size(), -1);

    Q.push(src);
    distance[src] = 0;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        if (farthest.second < distance[u]) {
            farthest = {u, distance[u]};
        }

        for (Node v : g[u]) {
            if (distance[v.node] == -1) {
                Q.push(v.node);
                distance[v.node] = distance[u] + v.cost;
            }
        }
    }

    return {farthest.first, distance};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ":\n";

        int n;
        cin >> n;

        vector<vector<Node>> g(n);
        for (int i = 1, u, v, w; i < n; ++i) {
            cin >> u >> v >> w;

            g[u].emplace_back(v, w);
            g[v].emplace_back(u, w);
        }

        pair<int, vector<int>> r1, r2;
        r1 = get_farthest(g, 0);
        r2 = get_farthest(g, r1.first);
        r1 = get_farthest(g, r2.first);

        for (int i = 0; i < n; ++i) {
            cout << max(r1.second[i], r2.second[i]) << "\n";
        }
    }

    return 0;
}
