#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void doomed() {
	int n;
	scanf("%d", &n);
	vector<vector<int>> banana(2 * n - 1);
	
	for(int i = 0; i < n; ++i) {
		for(int j = 0, x; j <= i; ++j) {
			scanf("%d", &x);
			banana[i].push_back(x);
		}
	}
	for(int i = n, k = 1; i < 2 * n - 1; ++i, ++k) {
		for(int j = n - k, x; j > 0; --j) {
			scanf("%d", &x);
			banana[i].push_back(x);
		}
	}
	
	if(n == 1) {
		printf("%d\n", banana[0][0]);
		return;
	}
	
	
	vector<vector<int>> dp = banana;
	for(int i = 0; i < n - 1; ++i) {
		for(int j = 0; j <= i; ++j) {
			dp[i + 1][j] = max(dp[i][j] + banana[i + 1][j], dp[i + 1][j]);
			dp[i + 1][j + 1] = dp[i][j] + banana[i + 1][j + 1];
		}
	}
	
	for(int i = 2 * n - 2, k = 0; i > n; --i, ++k) {
		for(int j = 0; j <= k; ++j) {
			dp[i - 1][j] = max(dp[i][j] + banana[i - 1][j], dp[i - 1][j]);
			dp[i - 1][j + 1] = dp[i][j] + banana[i - 1][j + 1];
		}
	}
	
	int mx = -1;
	for(int i = 0; i < n - 1; ++i) {
		mx = max({mx, dp[n][i] + dp[n - 1][i], dp[n][i] + dp[n - 1][i + 1]});
	}
	
	printf("%d\n", mx);
	
	// for(vector<int> d : dp) {
		// for(int x : d) {
			// printf("%d ", x);
		// }
		// puts("");
	// }
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
