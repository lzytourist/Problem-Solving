#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int INF = 1e9;

struct Node{
  int v, w;
  Node() = default;
  Node(int _v, int _w) {
    v = _v;
    w = _w;
  }
};

void doomed() {
  int n, m;
  scanf("%d%d", &n, &m);
  
  vector<vector<Node>> g(n + 1);
  for(int i = 0, u, v, w; i < m; ++i) {
    scanf("%d%d%d", &u, &v, &w);
    
    g[u].push_back(Node(v, w));
    g[v].push_back(Node(u, w));
  }
  
  priority_queue<pair<int, int>> Q;
  vector<int> dist(n + 1, INF);
  
  Q.push({0, 1});
  dist[1] = 0;
  
  while(!Q.empty()) {
    pair<int, int> u = Q.top();
    Q.pop();
        
    for(Node v : g[u.S]) {
      int cost = u.F + v.w;
      if(cost < dist[v.v]) {
        dist[v.v] = cost;
        Q.push({cost, v.v});
      }
    }
  }
  
  if(dist[n] == INF) {
    puts("Impossible");
    return;
  }
  printf("%d\n", dist[n]);
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
	
	int t;
	scanf("%d", &t);
	// cin >> t;
	
	for(int i = 1; i <= t; ++i) {
		printf("Case %d: ", i);
		// cout << "Case " << i << ": ";
		doomed();
	}
	
	return 0;
}
