#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define FOR(i, a, n) for(int i = a; i < n; ++i)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void doomed() {
	int n, m;
	scanf("%d%d", &n, &m);
	
	vector<int> k(n);
	vector<pair<int, bool>> c(m);
	
	for(int& x : k) scanf("%d", &x);
	for(pair<int, bool>& p : c) {
		scanf("%d", &p.F);
		p.S = true;
	}
	sort(k.begin(), k.end(), greater<int>());
	
	ll total = 0LL;
	
	for(int i = 0; i < n; ++i) {
		int l = 0, r = k[i] - 1, mid, pos = -1;
		
		while(l <= r) {
			mid = l + (r - l) / 2;
			if(c[mid].S) {
				pos = mid;
				r = mid - 1;
			} else {
				l = mid + 1;
			}
		}
		
		if(pos < 0) {
			total += c[k[i] - 1].F;
		} else {
			total += c[pos].F;
			c[pos].S = false;
		}
	}
	
	printf("%lld\n", total);
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);

	int t = 1;
	scanf("%d", &t);
	// cin >> t;

	while(t--) {
		doomed();
	}

  return 0;
}
