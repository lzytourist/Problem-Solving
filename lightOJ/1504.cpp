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

    int n;
    cin >> n;

    vector<vector<int>> cal(n);
    for (int i = 0, m; i < n; ++i) {
    	cin >> m;

    	cal[i].resize(m);
    	scan(cal[i]);

    	for (int j = 1; j < m; ++j) {
    		cal[i][j] += cal[i][j - 1];
    	}
    }

    int q;
    cin >> q;

    for (int qc = 1; qc <= q; ++qc) {
    	cout << "Query " << qc << ": ";

    	int c1, c2, d, m, y;
    	cin >> c1 >> c2 >> d >> m >> y;

    	--c1, --c2;

    	int total_days = cal[c1].back() * (y - 1);
    	if (m > 1) {
    		total_days += cal[c1][m - 2] + d;
    	} else {
    		total_days += d;
    	}

    	int year = total_days / cal[c2].back() + (total_days % cal[c2].back() != 0);
    	total_days -= cal[c2].back() * (year - 1);

    	int mm = lower_bound(cal[c2].begin(), cal[c2].end(), total_days) - cal[c2].begin();
    	
    	int dd = total_days - (mm > 0 ? cal[c2][mm - 1] : 0);
    	cout << dd << " " << mm + 1 << " " << year << endl;
    }

    return 0;
}