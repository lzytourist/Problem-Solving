#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in.txt", "r", stdin);
    freopen("/home/joker/Documents/code/out.txt", "w", stdout);
    #endif


    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n;
        cin >> n;

        ll sum = 0LL;
        for (ll i = 2; i * i <= 1LL * n; ++i) {
            ll j = n / i;

            sum += j * (j + 1) / 2LL;
            sum -= i * (i - 1) / 2LL;
            sum += i * (j - i);
        }

        cout << sum << endl;
    }

    return 0;
}

// j * (j + 1) / 2 - (i * (i - 1) / 2);