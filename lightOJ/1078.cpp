#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template<typename T>
void scan(vector<T> &v) {for (T &x : v) cin >> x;};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        ll divisor, digit, num;
        cin >> divisor >> digit;

        int need = 1;
        num = digit;

        for (int i = 0; ; ++i) {
            if (num % divisor == 0) break;

            num = (num * 10 + digit) % divisor;
            ++need;
        }

        cout << need << endl;
    }

    return 0;
}