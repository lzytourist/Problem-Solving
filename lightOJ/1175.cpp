#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<typename T>
void scan(vector<T> &v) {for (T &x : v) cin >> x;}

const int N = 200;
char g[N][N];
int dist[N][N], r, c;
vector<pair<int, int>> sides = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LUCHADOR
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        cin >> r >> c;

        int jx, jy;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                cin >> g[i][j];
                dist[i][j] = INT_MAX;

                if (g[i][j] == 'J') {
                    jx = i, jy = j;
                }
            }
        }

        int minutes = INT_MAX - 1;

        auto ok = [&](int sx, int sy) {
            return sx >= 0 && sx < r && sy >= 0 && sy < c && g[sx][sy] != '#';
        };

        auto BFS = [&](int x, int y, bool collect = false) {
            queue<pair<int, int>> Q;
            Q.push({x, y});
            dist[x][y] = 0;

            while (!Q.empty()) {
                pair<int, int> u = Q.front();
                Q.pop();

                if (collect && (u.F == 0 || u.S == 0 || u.F == r - 1 || u.S == c - 1)) {
                    minutes = min(minutes, dist[u.F][u.S]);
                }

                for (pair<int, int> &side : sides) {
                    int sx = side.F + u.F;
                    int sy = side.S + u.S;

                    if (ok(sx, sy) && dist[sx][sy] > dist[u.F][u.S] + 1) {
                        Q.push({sx, sy});
                        dist[sx][sy] = dist[u.F][u.S] + 1;
                    }
                }
            }
        };

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (g[i][j] == 'F') {
                    BFS(i, j);
                }
            }
        }

        BFS(jx, jy, true);

        ++minutes;
        
        if (minutes == INT_MAX) {
            cout << "IMPOSSIBLE" << endl;
        } else {
            cout << minutes << endl;
        }
    }

    return 0;
}