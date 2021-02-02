#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<pair<int, int>> sides {{1, 0}, {-1, 0}, {0, 1}, {0, -1}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};

bool ok(int x, int y, int n, int m, vector<vector<bool>>& vis) {
  return (x >= 0 && y >= 0 && x < n && y < m && !vis[x][y]);
}

void dfs(vector<string>& g, vector<vector<bool>>& vis, int n, int m, pair<int, int> u) {
  if(!vis[u.F][u.S]) {
    vis[u.F][u.S] = true;
    
    for(pair<int, int> side : sides) {
      int sx = side.F + u.F;
      int sy = side.S + u.S;
      
      if(ok(sx, sy, n, m, vis) && g[sx][sy] == '@') {
        dfs(g, vis, n, m, {sx, sy});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  int n, m;
  while(true) {
    cin >> n >> m;
    if(n == 0) break;
    
    vector<string> g(n);
    for(int i = 0; i < n; ++i) cin >> g[i];
    
    vector<vector<bool>> vis(n, vector<bool> (m, false));
    int oil = 0;
    
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(g[i][j] == '@' && !vis[i][j]) {
          ++oil;
          dfs(g, vis, n, m, {i, j});
        }
      }
    }
    
    cout << oil << endl;
  }
  
  return 0;
}
