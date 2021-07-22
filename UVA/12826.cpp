#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int r1, r2, r3, c1, c2, c3;
vector<pair<int, int>> sides = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {-1, -1}, {1, 1}, {-1, 1}, {1, -1}};

int bfs() {
	--r1, --r2, --r3, --c1, --c2, --c3;
	
	vector<vector<int>> lvl(8, vector<int>(8, -1));
	queue<pair<int, int>> Q;
	
	lvl[r3][c3] = -2;
	lvl[r1][c1] = 0;
	Q.push({r1, c1});
	
	auto ok = [&](int i, int j) {
		return i >= 0 && j >= 0 && i < 8 && j < 8 && lvl[i][j] == -1;
	};
	
	while(!Q.empty()) {
		pair<int, int> u = Q.front();
		Q.pop();
		
		for(pair<int, int> side : sides) {
			int sx = side.F + u.F;
			int sy = side.S + u.S;
			
			if(ok(sx, sy)) {
				lvl[sx][sy] = lvl[u.F][u.S] + 1;
				Q.push({sx, sy});
			}
		}
	}
	
	return lvl[r2][c2];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int tc = 0;
	while(cin >> r1 >> c1 >> r2 >> c2 >> r3 >> c3) {
		cout << "Case " << ++tc << ": ";
		cout << bfs() << endl;
	}
	
	return 0;
}
