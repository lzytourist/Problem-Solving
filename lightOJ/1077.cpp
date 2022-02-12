#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	for(int tc = 1; tc <= t; ++tc) {
		cout << "Case " << tc << ": ";
		
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		
		cout << __gcd(abs(a - c), abs(b - d)) + 1 << endl;
	}
	
	return 0;
}
