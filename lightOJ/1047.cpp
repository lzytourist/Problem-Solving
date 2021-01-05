#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct RGB {
	int r, g, b;
	RGB() {}
	RGB(int _r, int _g, int _b) {
		r = _r;
		g = _g;
		b = _b;
	}
};

int n;

int cost(vector<RGB>& h, int i, int forbidden, vector<vector<int>>& dp) {
	if(i >= n) return 0;
	if(dp[i][forbidden] != -1) {
		return dp[i][forbidden];
	}
	
	if(forbidden == 0) {
		int g = h[i].g + cost(h, i + 1, 1, dp);
		int b = h[i].b + cost(h, i + 1, 2, dp);
		
		dp[i][forbidden] = min(g, b);
		return min(g, b);
	}
	
	if(forbidden == 1) {
		int r = h[i].r + cost(h, i + 1, 0, dp);
		int b = h[i].b + cost(h, i + 1, 2, dp);
		
		dp[i][forbidden] = min(r, b);
		return min(r, b);
	}
	int r = h[i].r + cost(h, i + 1, 0, dp);
	int g = h[i].g + cost(h, i + 1, 1, dp);
	
	dp[i][forbidden] = min(r, g);
	return min(r, g);
}

void doomed() {
	scanf("%d", &n);
	
	vector<RGB> h(n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d%d", &h[i].r, &h[i].g, &h[i].b);
	}
	
	vector<vector<int>> dp(n, vector<int>(3, -1));
	printf("%d\n", min({cost(h, 0, 0, dp), cost(h, 0, 1, dp), cost(h, 0, 2, dp)}));
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
