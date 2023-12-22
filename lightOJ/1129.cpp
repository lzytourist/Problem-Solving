#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<typename T>
void scan(vector<T> &v) {for (T &x : v) cin >> x;}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LUCHADOR
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
    	cout << "Case " << tc << ": ";

    	int n;
    	cin >> n;

    	vector<string> a(n);
    	scan(a);

    	sort(a.begin(), a.end());

    	set<string> st;
    	int mx_length = 0;
    	bool consistent = true;

    	for (int i = 0; i < n; ++i) {
    		string x;

    		for (int j = 0; consistent && j < min(mx_length, (int) a[i].length()); ++j) {
    			x.pb(a[i][j]);

    			if (st.count(x)) {
    				consistent = false;
    			}
    		}

    		st.insert(a[i]);
    		mx_length = max(mx_length, (int) a[i].length());
    	}

    	cout << (consistent ? "YES" : "NO") << endl;
    }

    return 0;
}