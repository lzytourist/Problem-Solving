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

const int N = 1e4 + 1;
ll dp[N][2];

ll max_coin(vector<int> const &a, int idx, bool take = false) {
    if (idx >= (int) a.size()) {
        return 0LL;
    }

    if (dp[idx][take] != -1) {
        return dp[idx][take];
    }

    ll r1 = 0, r2 = 0;
    if (!take) {
        r1 = max_coin(a, idx + 1, true) + a[idx];
    }
    r2 = max_coin(a, idx + 1);

    return dp[idx][take] = max(r1, r2);
}

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

        vector<int> a(n);
        scan(a);

        memset(dp, -1LL, sizeof dp);

        cout << max_coin(a, 0) << endl;
    }

    return 0;
}