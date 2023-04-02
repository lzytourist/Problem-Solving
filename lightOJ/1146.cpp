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

typedef pair<double, double> pd;

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

        pd A, B, C, D;
        cin >> A.F >> A.S;
        cin >> B.F >> B.S;
        cin >> C.F >> C.S;
        cin >> D.F >> D.S;

        auto dist = [&](double spent) -> double {
            double speedABx = B.F - A.F;
            double speedABy = B.S - A.S;

            double speedDCx = D.F - C.F;
            double speedDCy = D.S - C.S;

            double x1 = A.F + spent * speedABx;
            double y1 = A.S + spent * speedABy;

            double x2 = C.F + spent * speedDCx;
            double y2 = C.S + spent * speedDCy;

            return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        };

        double l = 0.0, r = 1.0, m1, m2;
        int cnt = 64;

        while (cnt--) {
            m1 = l + (r - l) / 3.0;
            m2 = r - (r - l) / 3.0;

            if (dist(m1) <= dist(m2)) {
                r = m2;
            } else {
                l = m1;
            }
        }

        cout << fixed << setprecision(10) << sqrt(dist(l)) << endl;
    }

    return 0;
}