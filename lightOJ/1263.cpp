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

        int totalMoney = 0;
        vector<int> money(n);
        for (int &x : money) {
            cin >> x;
            totalMoney += x;
        }

        vector<vector<int>> g(n);
        for (int i = 0, u, v; i < m; ++i) {
            cin >> u >> v;
            --u, --v;

            g[u].push_back(v);
            g[v].push_back(u);
        }

        if (totalMoney % n != 0) {
            cout << "No\n";
            continue;
        }

        vector<bool> vis(n, false);
        queue<int> Q;
        bool can = true;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                Q.push(i);

                pair<int, int> they = {0, 0};
                while (!Q.empty()) {
                    int u = Q.front();
                    Q.pop();

                    // Connected people
                    // Money the connected people owns
                    they.first += 1;
                    they.second += money[u];

                    for (int v : g[u]) {
                        if (!vis[v]) {
                            vis[v] = true;
                            Q.push(v);
                        }
                    }
                }

                if (!(they.second % they.first == 0 && they.second / they.first == totalMoney / n)) {
                    can = false;
                    break;
                }
            }
        }

        cout << (can ? "Yes" : "No") << "\n";
    }

    return 0;
}
