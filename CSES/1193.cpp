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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> vis(n, vector<bool>(m, true));
    pair<int, int> st, en;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            char c;
            cin >> c;

            if (c == '.') {
                vis[i][j] = false;
            } else if (c == 'A') {
                st = {i, j};
            } else if (c == 'B') {
                en = {i, j};
                vis[i][j] = false;
            }
        }
    }

    queue<pair<int, int>> Q;
    Q.push(st);

    vector<vector<pair<int, int>>> path(n, vector<pair<int, int>>(m, {-1, -1}));


    while (!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();

        for (pair<int, int> &side : vector<pair<int, int>>(
            {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}
            )) {
            int sx = u.F + side.F;
            int sy = u.S + side.S;

            if (sx >= 0 && sx < n && sy >= 0 && sy < m && !vis[sx][sy]) {
                Q.push({sx, sy});
                vis[sx][sy] = true;

                path[sx][sy] = u;
            }
        }
    }

    if (path[en.F][en.S].F == -1) {
        cout << "NO" << endl;
        return 0;
    }

    stack<pair<int, int>> stk;
    while (!(en.F == st.F && en.S == st.S)) {
        stk.push(en);
        en = path[en.F][en.S];
    }

    cout << "YES" << endl << stk.size() << endl;

    while (!stk.empty()) {
        pair<int, int> u = stk.top();
        stk.pop();

        // cout << u.F - st.F << " " << u.S - st.S << endl;
        int x = u.F - st.F;
        int y = u.S - st.S;

        char c = 'U';
        if (x == 0 && y == -1) {
            c = 'L';
        } else if (x == 1 && y == 0) {
            c = 'D';
        } else if (x == 0 && y == 1) {
            c = 'R';
        }
        st = u;

        cout << c;
    }
    cout << endl;

    return 0;
}