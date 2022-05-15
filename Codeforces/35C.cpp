#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> lvl(n, vector<int>(m, INT32_MAX));
    int max_distance = 0;
    int x = 0, y = 0;
    
    while (k--) {
        int i, j;
        cin >> i >> j;
        --i, --j;
        
        queue<pair<int, int>> Q;
        
        lvl[i][j] = 0;
        Q.push({i, j});
        
        auto ok = [&](int i, int j) -> bool {
            return i >= 0 && j >= 0 && i < n && j < m;
        };
        
        while (!Q.empty()) {
            pair<int, int> u = Q.front();
            Q.pop();
            
            for (pair<int, int> const &side : vector<pair<int, int>>({{0, 1}, {1, 0}, {0, -1}, {-1, 0}})) {
                int sx = side.F + u.F;
                int sy = side.S + u.S;
                
                if (ok(sx, sy) && lvl[sx][sy] > lvl[u.F][u.S] + 1) {
                    Q.push({sx, sy});
                    
                    lvl[sx][sy] = min(lvl[sx][sy], lvl[u.F][u.S] + 1);
                }
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (lvl[i][j] >= max_distance) {
                max_distance = lvl[i][j];
                x = i + 1, y = j + 1;
            }
        }
    }
    
    cout << x << " " << y << endl;
    
    return 0;
}
