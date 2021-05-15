#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool can(vector<int>const& a, ll m, int M) {
	vector<ll> container(M, m);
	for(int i = 0, j = 0, n = a.size(); i < n; ) {
		if(j >= M) return false;

		if(container[j] - a[i] > 0) {
			container[j] -= a[i];
		} else if(container[j] - a[i] == 0) {
			container[j] = 0;
			++j;
		} else {
			++j;
			continue;
		}

		++i;
	}
	return true;
}

void doomed() {
	int n, M;
	cin >> n >> M;
	vector<int> a(n);
	for(int& x : a) cin >> x;

	ll l = 1LL, r = 1e12, m, p;
	while(l <= r) {
		m = l + (r - l) / 2;
		if(can(a, m, M)) {
			r = m - 1;
			p = m;
		} else {
			l = m + 1;
		}
	}

	cout << p << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	#ifdef lzytourist
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	int t;
	cin >> t;

	for(int i = 1; i <= t; ++i) {
		cout << "Case " << i << ": ";
		doomed();
	}

	return 0;
}
