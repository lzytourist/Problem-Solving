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

const int N = 75536;
vector<int> primes;

void gen() {
    bitset<N> prime;

    for (int i = 3; 1LL * i * i <= 1LL * N; i += 2) {
        if (!prime[i]) {
            for (int j = i * i; j < N; j += 2 * i) {
                prime[j] = true;
            }
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

#ifdef LUCHADOR
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    gen();

    int t;
    cin >> t;

    vector<ll> ans;
    ans.reserve(100);

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ":\n";

        ll n;
        cin >> n;

        ans.clear();
        ans.pb(1LL);

        for (int i = 0; i < (int) primes.size() && 1LL * primes[i] * primes[i] <= n; ++i) {
            if (n % primes[i] == 0) {
                int cnt = 0;
                while (n % primes[i] == 0) {
                    ++cnt;
                    n /= primes[i];
                }

                bool flag = false;
                int m = (int) ans.size();
                ll p = primes[i];

                while (cnt--) {
                    if (flag) {
                        for (int j = 0; j < m; ++j) {
                            ans.pb(ans[j] * p);
                        }
                    } else {
                        for (int j = m - 1; j >= 0; --j) {
                            ans.pb(ans[j] * p);
                        }
                    }

                    p *= primes[i];
                    flag = !flag;
                }
            }
        }

        if (n > 1) {
            int m = (int) ans.size();
            for (int j = m - 1; j >= 0; --j) {
                ans.pb(ans[j] * n);
            }
        }
        
        for (int i = 0; i < (int) ans.size(); ++i) {
            cout << ans[i] << " \n"[i + 1 == (int) ans.size()];
        }
    }

    return 0;
}