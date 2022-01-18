#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

bool bfs(vector<vector<int>> const &roads, int src, set<int> const &person) {
    vector<bool> vis(roads.size(), false);
    queue<int> Q;
    int people = 0;

    Q.push(src);
    vis[src] = true;

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();

        if (person.count(u)) {
            ++people;
        }

        for (int v : roads[u]) {
            if (!vis[v]) {
                vis[v] = true;
                Q.push(v);
            }
        }
    }

    return people == person.size();
}

int main() {
    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int k, n, m;
        cin >> k >> n >> m;

        set<int> person;
        for (int i = 0, x; i < k; ++i) {
            cin >> x;
            --x;
            person.insert(x);
        }

        vector<vector<int>> roads(n);
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            --u, --v;
            roads[v].push_back(u);
        }

        int cities = 0;
        for (int i = 0; i < n; ++i) {
            if (bfs(roads, i, person)) {
                ++cities;
            }
        }

        cout << cities << "\n";
    }

    return 0;
}
