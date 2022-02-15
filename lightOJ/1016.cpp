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
		
		int n, w;
		cin >> n >> w;
		
		vector<int> a(n);
		for(int i = 0, x, y; i < n; ++i) {
			cin >> x >> y;
			a[i] = y;
		}
		sort(a.begin(), a.end(), greater<int>());
		
		stack<int> stk;
		stk.push(a[0]);
		for(int i = 1; i < n; ++i) {
			int d = stk.top();
			
			if(d - a[i] > w) {
				stk.push(a[i]);
			}
		}
		
		cout << stk.size() << endl;
	}
	
	return 0;
}
