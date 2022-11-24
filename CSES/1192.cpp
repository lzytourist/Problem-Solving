#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template <typename T>
void scan(vector<T> &v) {for(T &x : v) {cin >> x;}}

bool vis[1000][1000];
int n, m;
vector<pair<int, int>> sides = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(int i, int j) {
    vis[i][j] = true;

    for (pair<int, int> const &side : sides) {
        int sx = side.F + i;
        int sy = side.S + j;

        if (sx >= 0 && sx < n && sy >= 0 && sy < m && !vis[sx][sy]) {
            dfs(sx, sy);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;

            vis[i][j] = (c == '#');
        }
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!vis[i][j]) {
                ++cnt;
                dfs(i, j);
            }
        }
    }

    cout << cnt << endl;

    return 0;
}