#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 65536 + 1;
set<int> primes;

void gen() {
    bitset<N> prime;
    for (int i = 3; i * i <= N; i += 2) {
        if (!prime[i]) {
            for (int j = i * i; j < N; j += 2 * i) {
                prime[j] = 1;
            }
        }
    }

    primes.insert(2);
    for (int i = 3; i < N; i += 2) {
        if (!prime[i]) {
            primes.insert(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    gen();

    int n;
    cin >> n;

    string s;
    cin >> s;

    n = s.length();
    ll num = 0, m;
    for (int i = 0; i < n; ++i) {
        if (s[i] == ',') {
            m = num;
            num = 0;
        } else if (i + 1 == n) {
            num = num * 10 + s[i] - '0';
            m = num;
        } else {
            num = num * 10 + s[i] - '0';
            continue;
        }

        if (!primes.count(m)) {
            cout << "No" << endl;
        } else {
            ll p1 = 1, p2 = 1;
            ll pow = m;

            while (pow > 0) {
                if (pow > 1) {
                    p1 <<= 1;
                }
                p2 <<= 1;
                --pow;
            }

            p2--;

            p1 *= p2;
            ll sum = 1LL;

            for (ll j = 2; j * j <= p1; ++j) {
                if (p1 % j == 0) {
                    sum += j;
                    if (p1 / j != j) {
                        sum += p1 / j;
                    }
                }
            }

            if (p1 == sum) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
