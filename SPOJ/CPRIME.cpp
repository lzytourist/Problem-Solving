#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e8 + 1;
vector<int> primes;
bitset<N> prime;

void gen() {
	for (int i = 3; 1LL * i * i <= 1LL * N; i += 2) {
		if (!prime[i]) {
			for (ll j = 1LL * i * i; j < N; j += 2LL * i) {
				prime[j] = 1;
			}
		}
	}
	
	primes.pb(2);
	for (int i = 3; i < N; i += 2) {
		if (!prime[i]) {
			primes.pb(i);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	gen();
	
	int n;
	while(cin >> n) {
		if (n == 0) {
			break;
		}
		
		int l = 0, r = primes.size() - 1, m, p = -1;
		while (l <= r) {
			m = l + (r - l) / 2;
			if (primes[m] <= n) {
				p = m;
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		
		++p;
		
		double s = abs(1.0 * p - (1.0 * n / log1p(1.0 * (n - 1))));
		cout << fixed << setprecision(1);
		cout << (100 * s) / p << endl;
	}
	
	return 0;
}
