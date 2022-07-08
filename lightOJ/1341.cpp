#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

const int N = 1e6 + 1;
vector<int> primes;

void gen() {
    bitset<N> prime;
    for (int i = 3; 1LL * i * i <= 1LL * N; i += 2) {
        if (!prime[i]) {
            for (long long j = 1LL * i * i; j < 1LL * N; j += 2LL * i) {
                prime[j] = true;
            }
        }
    }

    primes.push_back(2);
    for (int i = 3; i < N; i += 2) {
        if (!prime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    gen();

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        unsigned long long area, min_side, x;
        cin >> area >> min_side;
        x = area;

        if (min_side * min_side >= area) {
            cout << 0 << "\n";
            continue;
        }

        long long divisors = 1;
        for (int i = 0; i < (int) primes.size() && 1LL * primes[i] * primes[i] <= area; ++i) {
            if (area % primes[i] == 0) {
                int cnt = 0;
                while (area % primes[i] == 0) {
                    ++cnt;
                    area /= primes[i];
                }
                divisors *= (cnt + 1);
            }
        }

        if (area > 1) {
            divisors *= 2;
        }

        divisors >>= 1;
        for (unsigned long long i = 1; i < min_side; ++i) {
            divisors -= (x % i == 0);
        }

        cout << divisors << "\n";
    }

    return 0;
}
