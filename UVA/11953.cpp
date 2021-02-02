#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<pair<int, int>> sides {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

bool ok(int x, int y, int n, vector<vector<bool>>& vis) {
  return (x >= 0 && y >= 0 && x < n && y < n && !vis[x][y]);
}

bool alive;
void dfs(vector<string>& g, vector<vector<bool>>& vis, int n, pair<int, int> u) {
  if(g[u.F][u.S] == 'x') alive = true;
  
  if(!vis[u.F][u.S]) {
    vis[u.F][u.S] = true;
    
    for(pair<int, int> side : sides) {
      int sx = side.F + u.F;
      int sy = side.S + u.S;
      
      if(ok(sx, sy, n, vis) && g[sx][sy] != '.') {
        dfs(g, vis, n, {sx, sy});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  int t, n;
  cin >> t;
  for(int k = 1; k <= t; ++k) {
    cin >> n;
    vector<string> g(n);
    for(int i = 0; i < n; ++i) cin >> g[i];
    
    vector<vector<bool>> vis(n, vector<bool> (n, false));
    int ships = 0;
    
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(g[i][j] != '.' && !vis[i][j]) {
          alive = false;
          dfs(g, vis, n, {i, j});
          
          if(alive) ++ships;
        }
      }
    }
    
    cout << "Case " << k << ": " << ships << endl;
  }
  
  return 0;
}
