#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 10000;

bitset<N> visited;
vector<int> components;
int roots[N], indeg[N];
vector<int> g[N], gr[N];

void dfs(int u, stack<int> &stk) {
	visited[u] = true;
	
	for (int v : g[u]) {
		if (!visited[v]) {
			dfs(v, stk);
		}
	}
	
	stk.push(u);
}

void dfs(int u) {
	visited[u] = true;
	
	components.pb(u);
	
	for (int v : gr[u]) {
		if (!visited[v]) {
			dfs(v);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	for (int tc = 1; tc <= t; ++tc) {
		cout << "Case " << tc << ": ";
		
		int n, m;
		cin >> n >> m;
		
		for (int i = 0; i < n; ++i) {
			g[i].clear();
			gr[i].clear();
			visited[i] = false;
			roots[i] = i;
		}
		
		for (int i = 0, u, v; i < m; ++i) {
			cin >> u >> v;
			--u, --v;
			
			g[u].pb(v);
			gr[v].pb(u);
		}
		
		stack<int> stk;
		
		for (int i = 0; i < n; ++i) {
			if (!visited[i]) {
				dfs(i, stk);
			}
		}
		
		for (int i = 0; i < n; ++i) {
			visited[i] = false;
			indeg[i] = 0;
		}
		
		while (!stk.empty()) {
			int u = stk.top();
			stk.pop();
			
			if (!visited[u]) {
				components.clear();
				dfs(u);
				
				for (int i = 1; i < (int) components.size(); ++i) {
					roots[components[i]] = components[0];
				}
			}
		}
		
		for (int u = 0; u < n; ++u) {
			for (int v : g[u]) {
				if (roots[u] != roots[v]) {
					indeg[roots[v]]++;
				}
			}
		}
		
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			if (i != roots[i]) continue;
			
			if (indeg[i] == 0) ++cnt;
		}
		
		cout << cnt << endl;
	}
	
	return 0;
}
