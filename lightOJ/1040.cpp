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

pair<int, int> parent[50];

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n;
        cin >> n;

        priority_queue<Edge> Q;
        int total = 0;

        for (int i = 0, c; i < n; ++i) {
            parent[i] = {i, i};
            for (int j = 0; j < n; ++j) {
                cin >> c;
                total += c;

                if (c != 0) {
                    Q.emplace(i, j, c);
                }
            }
        }

        int used = 0;
        while (!Q.empty()) {
            Edge edge = Q.top();
            Q.pop();

            if (find_set(edge.u) != find_set(edge.v)) {
                union_set(edge.u, edge.v);
                used += edge.c;
            }
        }

        int comp;
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (i == 0) {
                comp = find_set(i);
            } else if (comp != find_set(i)) {
                ok = false;
                break;
            }
        }

        if (!ok) {
            cout << "-1\n";
        } else {
            cout << total - used << "\n";
        }
    }

    return 0;
}
