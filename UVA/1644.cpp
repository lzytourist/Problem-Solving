#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1299710;
vector<int> primes;

void gen() {
	bitset<N> prime;
	for(int i = 3; 1LL * i * i <= 1LL * N; i += 2) {
		if(!prime[i]) {
			for(ll j = 1LL * i * i; j < N; j += 2LL * i) {
				prime[j] = 1;
			}
		}
	}
	
	primes.pb(2);
	for(int i = 3; i < N; i += 2) {
		if(!prime[i]) {
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
		if(n == 0) {
			break;
		}
		
		bool prime = false;
		int l = 0, r = 100000 - 1, m, p = 0;
		while(l <= r) {
			m = l + (r - l) / 2;
			if(primes[m] >= n) {
				r = m - 1;
				p = m;
				
				if(primes[m] == n) {
					prime = true;
					break;
				}
			} else {
				l = m + 1;
			}
		}
		
		if(prime) {
			cout << 0 << endl;
		} else {
			cout << primes[p] - primes[p - 1] << endl;
		}
	}
	
	return 0;
}
