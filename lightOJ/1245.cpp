#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n;
        cin >> n;

        ll res = 1LL * (n - n / 2);
        for (int i = n / 2; i >= 1; --i) {
            int d = n / i;

            int up = n / (d + 1LL);
            ++up;

            res += 1LL * (i - up + 1) * 1LL * d;
            i = up;
        }

        cout << res << endl;
    }

    return 0;
}
