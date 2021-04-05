#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9 + 7;

struct Node {
  int v, w;
  Node() = default;
  Node(int _v, int _w) {
    v = _v;
    w = _w;
  }
};

void doomed() {
  int n, m, s, t;
  cin >> n >> m >> s >> t;
  vector<vector<Node>> g(n);
  for(int i = 0, u, v, w; i < m; ++i) {
    cin >> u >> v >> w;
    g[u].push_back(Node(v, w));
    g[v].push_back(Node(u, w));
  }
  
  vector<int> dist(n, INF);
  priority_queue<pii, vector<pii>, greater<pii>> Q;
  Q.push({0, s});
  dist[s] = 0;
  
  while(!Q.empty()) {
    pii u = Q.top();
    Q.pop();
    
    if(dist[u.S] != u.F) continue;
    
    for(Node v : g[u.S]) {
      int cost = v.w + u.F;
      if(cost < dist[v.v]) {
        dist[v.v] = cost;
        Q.push({cost, v.v});
      }
    }
  }
  
  if(dist[t] == INF) {
    cout << "unreachable" << endl;
  } else {
    cout << dist[t] << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  
  for(int i = 0; i < t; ++i) {
    cout << "Case #" << i + 1 << ": ";
    doomed();
  }  
  
  return 0;
}
