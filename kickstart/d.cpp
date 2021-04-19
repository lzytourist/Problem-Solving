#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;

const ull INF = ULONG_LONG_MAX;

struct Node{
  int v, l;
  ll a;
  Node() = default;
  Node(int _v, int _l, ll _a) {
    v = _v, l = _l, a = _a;
  }
};

vector<ull> gcds;

void bfs(vector<vector<Node>>const& g, int n, vector<Node>& path) {
  queue<int> Q;
  vector<bool> vis(n + 1, false);
  
  Q.push(1);
  vis[1] = true;
  
  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();
    
    for(Node v : g[u]) {
      if(!vis[v.v]) {
        vis[v.v] = true;
        Q.push(v.v);
        
        path[v.v] = Node(u, v.l, v.a);
      }
    }
  }
}

void print_path(vector<Node>const& path, int p, int w) {
  if(p == -1) return;
  print_path(path, path[p].v, w);
  
  if(w >= path[p].l) {
    if(path[p].a) gcds.push_back(path[p].a);
  }
  
  // cout << p << "(" << ((w >= path[p].l) ? path[p].a : 0) << ") ";
}

void doomed() {
  int n, q;
  cin >> n >> q;
  
  vector<vector<Node>> g(n + 1);
  
  for(int i = 1, x, y, l; i < n; ++i) {
    ll a;
    cin >> x >> y >> l >> a;
    g[x].push_back(Node(y, l, a));
    g[y].push_back(Node(x, l, a));
  }
  
  vector<Node> path(n + 1);
  path[1] = Node(-1, 0, 0);
  bfs(g, n, path);
  
  // for(Node x : path) {
    // cout << x.v << " " << x.l << " " << x.a << endl;
  // }
  
  for(int i = 1; i <= q; ++i) {
    int c, w;
    cin >> c >> w;
    
    gcds.clear();
    print_path(path, c, w);
    
    if(gcds.size() == 0) {
      cout << 0;
    } else {
      ull gcd = 0;
      
      for(ull x : gcds) {
        if(gcd == 0) gcd = x;
        else {
          gcd = __gcd(gcd, x);
        }
      }
      
      cout << gcd;
    }
    
    if(i < q) cout << " ";
    else cout << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  
  for(int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    doomed();
  }
  
  return 0;
}
