#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n, m;
        cin >> n >> m;

        vector<vector<char>> g(n, vector<char>(m));
        vector<vector<int>> distance(n, vector<int>(m, -1));
        queue<pair<int, int>> Q;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> g[i][j];

                if (g[i][j] == 'h') {
                    Q.push({i, j});
                    distance[i][j] = 0;
                }
            }
        }

        auto ok = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m && g[i][j] != '#' && g[i][j] != 'm' && distance[i][j] == -1;
        };

        int maxDistance = 0;
        while (!Q.empty()) {
            pair<int, int> u = Q.front();
            Q.pop();

            if (g[u.first][u.second] == 'a' || g[u.first][u.second] == 'b' || g[u.first][u.second] == 'c') {
                maxDistance = max(maxDistance, distance[u.first][u.second]);
            }

            for (pair<int, int> const &p : vector<pair<int, int>>({{0, 1}, {1, 0}, {-1, 0}, {0, -1}})) {
                int sx = u.first + p.first;
                int sy = u.second + p.second;

                if (ok(sx, sy)) {
                    distance[sx][sy] = distance[u.first][u.second] + 1;
                    Q.push({sx, sy});
                }
            }
        }

        cout << maxDistance << "\n";
    }

    return 0;
}
