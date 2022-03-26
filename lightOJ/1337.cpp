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
        cout << "Case " << tc << ":\n";

        int m, n, q;
        cin >> n >> m >> q;

        vector<vector<char>> g(n, vector<char>(m));
        vector<vector<int>> crystal(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> g[i][j];
            }
        }

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<vector<bool>> vis2(n, vector<bool>(m, false));

        auto ok = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m && !vis[i][j] && g[i][j] != '#';
        };

        auto ok2 = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m && !vis2[i][j] && g[i][j] != '#';
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (g[i][j] == 'C' && !vis[i][j]) {
                    queue<pair<int, int>> Q;
                    vis[i][j] = true;
                    Q.push({i, j});

                    while (!Q.empty()) {
                        pair<int, int> u = Q.front();
                        Q.pop();

                        if (g[u.first][u.second] == 'C') {
                            ++crystal[i][j];
                        }

                        for (pair<int, int> const &p : vector<pair<int, int>>({{0, 1}, {1, 0}, {-1, 0}, {0, -1}})) {
                            int sx = u.first + p.first;
                            int sy = u.second + p.second;

                            if (ok(sx, sy)) {
                                vis[sx][sy] = true;
                                Q.push({sx, sy});
                            }
                        }
                    }


                    vis2[i][j] = true;
                    Q.push({i, j});

                    while (!Q.empty()) {
                        pair<int, int> u = Q.front();
                        Q.pop();

                        crystal[u.first][u.second] = crystal[i][j];

                        for (pair<int, int> const &p : vector<pair<int, int>>({{0, 1}, {1, 0}, {-1, 0}, {0, -1}})) {
                            int sx = u.first + p.first;
                            int sy = u.second + p.second;

                            if (ok2(sx, sy)) {
                                vis2[sx][sy] = true;
                                Q.push({sx, sy});
                            }
                        }
                    }
                }
            }
        }

        while (q--) {
            int x, y;
            cin >> x >> y;

            cout << crystal[x - 1][y - 1] << "\n";
        }
    }

    return 0;
}
