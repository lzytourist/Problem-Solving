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

const int B = 31;
const int M = 1e9 + 7;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int m;
    while (cin >> m) {
        string needle, haystack;
        cin >> needle >> haystack;

        int n = (int) haystack.length();
        vector<int> hashes(n + 1), bases(n + 1);
        hashes[0] = 0, bases[0] = 1;

        for (int i = 1; i <= n; ++i) {
            hashes[i] = (1LL * hashes[i - 1] * B + (haystack[i - 1] - 'a' + 1)) % M;
            bases[i] = (1LL * bases[i - 1] * B) % M;
        }

        int pHash = 0;
        for (int i = 0; i < m; ++i) {
            pHash = (1LL * pHash * B + (needle[i] - 'a' + 1)) % M;
        }

        queue<int> Q;
        for (int i = m; i <= n; ++i) {
            int h = hashes[i] - (1LL * hashes[i - m] * bases[m]) % M;
            if (h < 0) h += M;

            if (h == pHash) {
                Q.push(i - m);
            }
        }

        if (Q.empty()) {
            cout << endl;
        } else {
            while (!Q.empty()) {
                cout << Q.front() << endl;
                Q.pop();
            }
        }
    }

    return 0;
}