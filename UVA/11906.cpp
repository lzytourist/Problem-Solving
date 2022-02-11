#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void doomed() {
	int r, c, m, n;
	cin >> r >> c >> m >> n;
	
	vector<vector<char>> grid(r, vector<char>(c, '.'));
	int w;
	cin >> w;
	
	while(w--) {
		int x, y;
		cin >> x >> y;
		
		grid[x][y] = 'W';
	}
	
	queue<pair<int, int>> Q;
	vector<vector<bool>> vis(r, vector<bool>(c, false));
	vector<pair<int, int>> sides = {{m, n}, {n, m}, {-m, n}, {n, -m}, {m, -n}, {-n, m}, {-m, -n}, {-n, -m}};
	int even = 0, odd = 0;
	
	Q.push({0, 0});
	vis[0][0] = true;
	
	auto ok = [&](int i, int j) -> bool {
		return i >= 0 && j >= 0 && i < r && j < c && grid[i][j] != 'W';
	};
	
	while(!Q.empty()) {
		pair<int, int> u = Q.front();
		Q.pop();
		
		set<pair<int, int>> st;
		for(pair<int, int> const &side : sides) {
			int sx = side.F + u.F;
			int sy = side.S + u.S;
			
			if (ok(sx, sy)) {
				if (!vis[sx][sy]) {
					Q.push({sx, sy});
					vis[sx][sy] = true;
				}
				
				st.insert({sx, sy});
			}
		}
		
		int cnt = st.size();
		(cnt & 1) ? ++odd : ++even;
	}
	
	cout << even << " " << odd << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	for(int tc = 1; tc <= t; ++tc) {
		cout << "Case " << tc << ": ";
		doomed();
	}
	
	return 0;
}
