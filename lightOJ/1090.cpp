#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e6 + 1;
vector<ll> fives(N), twos(N);

void doomed() {
	int n, r, p, q;
	cin >> n >> r >> p >> q;

	ll F, T;
	F = fives[n];
	T = twos[n];

	F -= fives[r];
	F -= fives[n - r];

	T -= twos[r];
	T -= twos[n - r];

	int five = 0, two = 0;
	int x = p;

	while(x % 5 == 0) {
		++five;
		x /= 5;
	}

	x = p;
	while(x % 2 == 0) {
		++two;
		x /= 2;
	}

	F += 1LL * five * q;
	T += 1LL * two * q;

	cout << min(F, T) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	#ifdef lzytourist
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	#endif

	fives[0] = fives[1] = fives[2] = fives[3] = fives[4] = 0;
	twos[0] = twos[1] = 0;
	for(int i = 2, x; i < N; ++i) {
		fives[i] = 0, twos[i] = 0;

		x = i;
		while(x % 5 == 0) {
			++fives[i];
			x /= 5;
		}

		x = i;
		while(x % 2 == 0) {
			++twos[i];
			x /= 2;
		}

		fives[i] += fives[i - 1];
		twos[i] += twos[i - 1];
	}

	int t = 1;
	cin >> t;

	for(int i = 1; i <= t; ++i) {
		cout << "Case #" << i << ": ";
		doomed();
	}

	return 0;
}
