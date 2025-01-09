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

const int N = 2001;

ll dp[N][N];

ll knap(vector<pair<int, ll>> const &a, int idx, int w) {
    if (w < 0) return -1e18;
    if (idx >= (int) a.size() || w == 0) return 0LL;

    if (dp[idx][w] != -1) return dp[idx][w];

    ll r1 = knap(a, idx + 1, w);
    ll r2 = knap(a, idx + 1, w - a[idx].F) + a[idx].S;

    // cout << idx << " " << r1 << " " << r2 << endl;

    return dp[idx][w] = max(r1, r2);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LUCHADOR
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int w, n;
    cin >> w >> n;

    vector<pair<int, ll>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].F >> a[i].S;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            dp[i][j] = -1;
        }
    }

    cout << max(0LL, knap(a, 0, w)) << endl;

    return 0;
}