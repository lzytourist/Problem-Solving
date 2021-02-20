#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, m, resturants;

void dfs(vector<vector<int>>& g, int u, int can, vector<bool>& vis, vector<int>& cat) {
  vis[u] = true;
  
  // printf("%d %d\n", u, can);
  
  bool leaf = true;
  for(int v : g[u]) {
    if(!vis[v]) {
      leaf = false;
      if(cat[v] == 1) {
        dfs(g, v, can - 1, vis, cat);
      } else if(can >= 0) {
        dfs(g, v, m, vis, cat);
      }
    }
  }
  
  if(can >= 0 && leaf) {
    ++resturants;
  }
}

int main()
{
  scanf("%d%d", &n, &m);
  
  vector<int> cat(n);
  for(int& x : cat) scanf("%d", &x);
  
  vector<vector<int>> g(n);
  for(int i = 1, u, v; i < n; ++i) {
    scanf("%d%d", &u, &v);
    --u, --v;
    
    g[u].push_back(v);
    g[v].push_back(u);
  }
  
  vector<bool> vis(n, false);
  dfs(g, 0, m - cat[0], vis, cat);
  
  printf("%d\n", resturants);
}
