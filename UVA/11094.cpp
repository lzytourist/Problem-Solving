#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m, x, y, regions;
vector<pair<int, int>> sides {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(vector<string>& g, int i, int j, char land, vector<vector<bool>>& vis) {
  if(!vis[i][j]) {
    vis[i][j] = true;
    
    for(pair<int, int> side : sides) {
      int sx = side.F + i;
      int sy = side.S + j;
      
      if(sy == -1) sy = m - 1;
      if(sy == m) sy = 0;
      
      if(sx >= 0 && sy >= 0 && sx < n && sy < m && !vis[sx][sy] && g[sx][sy] == land) {
        ++regions;
        dfs(g, sx, sy, land, vis);
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  while(cin >> n >> m) {
    vector<string> g(n);
    for(string& s : g) cin >> s;
    cin >> x >> y;
    
    char land = g[x][y];
    int mx = 0;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    dfs(g, x, y, land, vis);
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < m; ++j) {
        if(g[i][j] == land && !vis[i][j]) {
          regions = 1;
          dfs(g, i, j, land, vis);
          mx = max(mx, regions);
        }
      }
    }
    
    cout << mx << endl;
  }
  
  return 0;
}
