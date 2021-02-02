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

void dfs(vector<string>& g, vector<vector<bool>>& vis, int n, pair<int, int> u) {
  if(!vis[u.F][u.S]) {
    vis[u.F][u.S] = true;
    
    for(pair<int, int> side : sides) {
      int sx = side.F + u.F;
      int sy = side.S + u.S;
      
      if(ok(sx, sy, n, vis) && g[sx][sy] == '1') {
        dfs(g, vis, n, {sx, sy});
      }
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  int n, t = 1;
  while(cin >> n) {    
    vector<string> g(n);
    for(int i = 0; i < n; ++i) cin >> g[i];
    
    vector<vector<bool>> vis(n, vector<bool> (n, false));
    int eagle = 0;
    
    for(int i = 0; i < n; ++i) {
      for(int j = 0; j < n; ++j) {
        if(g[i][j] == '1' && !vis[i][j]) {
          ++eagle;
          dfs(g, vis, n, {i, j});
        }
      }
    }
    
    cout << "Image number " << t <<  " contains " << eagle << " war eagles." << endl;
    ++t;
  }
  
  return 0;
}
