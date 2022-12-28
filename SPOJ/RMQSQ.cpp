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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int n, LOG = 18;
    cin >> n;

    vector<vector<int>> sparse(n, vector<int>(LOG));
    for (int i = 0; i < n; ++i) {
        cin >> sparse[i][0];
    }

    for (int j = 1; j < LOG; ++j) {
        for (int i = 0; i + (1 << j) - 1 < n; ++i) {
            sparse[i][j] = min(sparse[i][j - 1], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }

    int q;
    cin >> q;

    while (q--) {
        int l, r;
        cin >> l >> r;

        int len = r - l + 1;
        int j = __lg(len);

        cout << min(sparse[l][j], sparse[r - (1 << j) + 1][j]) << endl;
    }

    return 0;
}