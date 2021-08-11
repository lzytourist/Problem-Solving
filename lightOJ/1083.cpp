#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void doomed() {
	int n;
	cin >> n;
	
	int mx = 0;
	stack<pair<int, int>> stk;
	stk.push({0, 0});
	
	for(int i = 1, x; i <= n + 1; ++i) {
		if(i <= n) {
			cin >> x;
		} else {
			x = 0;
		}
		
		while(stk.top().F > x) {
			pair<int, int> a = stk.top();stk.pop();
			pair<int, int> b = stk.top();
			
			int d = a.S - b.S;
			d += i - 1 - a.S;
			mx = max(mx, d * a.F);
		}
		
		if(stk.top().F == x) {
			stk.pop();
			stk.push({x, i});
		} else {
			stk.push({x, i});
		}
	}
	
	cout << mx << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; ++i) {
		cout << "Case " << i << ": ";
		doomed();
	}
	
	return 0;
}
