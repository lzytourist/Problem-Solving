#include <iostream>
#include <vector>

using namespace std;

class Hash {
    static const int M = 1e9 + 9;
    static const int P = 9973;

    static vector<long long> pow;
    vector<long long> p_hash;

public:
    explicit Hash(string const &s): p_hash(s.size() + 1) {
        while(pow.size() < s.size()) {
            pow.push_back((pow.back() * P) % M);
        }

        p_hash[0] = 0;
        for (int i = 0; i < (int) s.size(); ++i) {
            p_hash[i + 1] = ((p_hash[i] * P) % M + s[i]) % M;
        }
    }

    long long getHash(int i, int j) {
        long long raw_val = (
                p_hash[j + 1] - (p_hash[i] * pow[j - i + 1])
                );
        return (raw_val % M + M) % M;
    }
};
vector<long long> Hash::pow = {1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        string a, b;
        cin >> a >> b;

        int n = (int) a.size();
        int m = (int) b.size();

        Hash h1(a), h2(b);
        long long cmp = h2.getHash(0, m - 1);
        int cnt = 0;

        for (int i = 0, j = m - 1; j < n; ++j, ++i) {
            if (h1.getHash(i, j) == cmp) {
                ++cnt;
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
