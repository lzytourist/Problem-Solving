#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 2e6;
vector<int> primes;

void gen() {
    bitset<N> prime;

    for (int i = 3; 1LL * i * i <= N; i += 2) {
        for (ll j = 1LL * i * i; j < N; j += 2LL * i) {
            prime[j] = true;
        }
    }

    primes.pb(2);
    for (int i = 3; i < N; i += 2) {
        if (!prime[i]) {
            primes.pb(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in.txt", "r", stdin);
    freopen("/home/joker/Documents/code/out.txt", "w", stdout);
    #endif

    gen();

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n;
        cin >> n;

        ll cost = 0LL;
        for (int i = 0, x; i < n; ++i) {
            cin >> x;

            int l = 0, r = primes.size() - 1, m, p = 0;
            while (l <= r) {
                m = l + (r - l) / 2;

                if (primes[m] > x) {
                    p = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }

            cost += 1LL * primes[p];
        }

        cout << cost << " Xukha" << endl;
    }

    return 0;
}