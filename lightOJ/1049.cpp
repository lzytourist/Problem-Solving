#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> const &roads, vector<bool> &vis, int u, vector<int> &circle) {
    vis[u] = true;
    circle.push_back(u);

    for (int v : roads[u]) {
        if (!vis[v]) {
            dfs(roads, vis, v, circle);
        }
    }
}

int calculate(vector<int> const &circle, map<pair<int, int>, int> const &cost) {
    int sum = 0;
    for (int i = 1; i < (int) circle.size(); ++i) {
        if (cost.find({circle[i - 1], circle[i]}) == cost.end()) {
            sum += cost.at({circle[i], circle[i - 1]});
        }
    }

    if (cost.find({circle.back(), circle.front()}) == cost.end()) {
        sum += cost.at({circle.front(), circle.back()});
    }

    return sum;
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

        vector<vector<int>> roads(n);
        map<pair<int, int>, int> cost;
        for (int i = 0, u, v, c; i < n; ++i) {
            cin >> u >> v >> c;
            --u, --v;

            roads[u].push_back(v);
            roads[v].push_back(u);

            cost[{u, v}] = c;
        }

        vector<int> circle1, circle2;
        vector<bool> vis(n, false);
        dfs(roads, vis, 0, circle1);

        vis.assign(n, false);
        reverse(roads[0].begin(), roads[0].end());
        dfs(roads, vis, 0, circle2);

        int r1 = calculate(circle1, cost);
        int r2 = calculate(circle2, cost);

        cout << min(r1, r2) << "\n";
    }

    return 0;
}
