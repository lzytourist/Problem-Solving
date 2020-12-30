#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define PI acos(-1.0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int a[501][501];

void test_case() {
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			scanf("%d", &a[i][j]);
		}
	}
	
	map<pair<int, int>, bool> good;
	for(int i = 0; i < m; ++i) {
		int x = 0, y = i;
		while(x < n && y < m) {
			if(a[0][i] != a[x][y]) {
				good[{0, i}] = false;
				break;
			}
			++x, ++y;
		}
	}
	for(int i = 1; i < n; ++i) {
		int x = i, y = 0;
		while(x < n && y < m) {
			if(a[i][0] != a[x][y]) {
				good[{i, 0}] = false;
				break;
			}
			++x, ++y;
		}
	}
	
	int q;
	scanf("%d", &q);
	
	loop: while(q--) {
		int x, y, v;
		scanf("%d%d%d", &x, &y, &v);
		--x, --y;
		a[x][y] = v;
		
		int mn = min(x, y);
		int i = x - mn;
		int j = y - mn;
		int need = a[i][j];
		
		bool ok = true;
		while(i < n && j < m) {
			if(a[i][j] != need) {
				ok = false;
				break;
			}
			++i, ++j;
		}
		good[{x - mn, y - mn}] = ok;
		
		for(pair<pair<int, int>, bool> pos : good) {
			if(!pos.S) {
				puts("No");
				goto loop;
			}
		}
		
		puts("Yes");
	}
}

int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);

    int t;
    // cin >> t;
    scanf("%d", &t);

    for(int i = 1; i <= t; ++i) {
        // printf("Case %d: ", i);
        test_case();
    }

    return 0;
}

