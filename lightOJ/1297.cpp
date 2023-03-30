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

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LUCHADOR
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        double h, w;
        cin >> h >> w;

        auto vol = [&](double x) -> double {
            double H = h - 2 * x;
            double W = w - 2 * x;

            if (H < 0 && W < 0) {
                return 0.0;
            }
            return H * W * x;
        };

        double low = 0, high = min(h, w), m1, m2;
        int cnt = 64;

        while (cnt--) {
            m1 = low + (high - low) / 3;
            m2 = high - (high - low) / 3;

            if (vol(m1) <= vol(m2)) {
                low = m1;
            } else {
                high = m2;
            }
        }

        cout << fixed << setprecision(10);
        cout << vol(low) << endl;
    }

    return 0;
}