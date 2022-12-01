#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template <typename T>
void scan(vector<T> &v) {for(T &x : v) {cin >> x;}}

const int N = 1000;
short dp[N + 1][N];
vector<int> path[N];


int palindrome(string const &s, int b, int e) {
    if (b >= e) return 1;

    if (dp[b][e] != -1) return dp[b][e];

    if (s[b] == s[e]) {
        dp[b][e] = palindrome(s, b + 1, e - 1);
    } else {
        dp[b][e] = 0;
    }

    return dp[b][e];
}

int run(int p, int const &n) {
    if (p >= n) {
        return 0;
    }

    if (dp[N][p] != -1) return dp[N][p];

    int cnt = n;
    for (int const &x : path[p]) {
        cnt = min(run(x + 1, n) + 1, cnt);
    }

    return dp[N][p] = cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        string s;
        cin >> s;

        int n = (int) s.length();
        for (int i = 0; i < n; ++i) {
            path[i].clear();
            for (int j = 0; j < n; ++j) {
                dp[i][j] = -1;
                dp[N][j] = -1;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (palindrome(s, i, j)) {
                    path[i].pb(j);
                }
            }
        }
        
        cout << run(0, n) << endl;
    }

    return 0;
}