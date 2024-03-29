#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e7;
bitset<N> prime;
vector<int> primes;

void gen() {
    for (int i = 3; 1LL * i * i <= 1LL * N; i += 2) {
        if (!prime[i]) {
            for (ll j = 1LL * i * i; j < N; j += 2LL * i) {
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

inline bool isPrime(int n) {
    if (n == 2) {
        return true;
    }
    return (n & 1) && prime[n] != true;
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
        
        int cnt = 0;
        for (int i = 0; i < (int) primes.size() && primes[i] <= n - primes[i]; ++i) {
            if (isPrime(primes[i]) && isPrime(n - primes[i])) {
                ++cnt;
            }
        }

        cout << cnt << endl;
    }

    return 0;
}