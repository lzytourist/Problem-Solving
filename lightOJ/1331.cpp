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

        double r[3];
        cin >> r[0] >> r[1] >> r[2];

        sort(r, r + 3);

        double a = r[0] + r[1];
        double b = r[0] + r[2];
        double c = r[1] + r[2];

        double arc[3];
        arc[0] = acos((a * a + b * b - c * c) / (2 * a * b));
        arc[0] = arc[0] * 180 / acos(-1);

        arc[1] = acos((a * a + c * c - b * b) / (2 * a * c));
        arc[1] = arc[1] * 180 / acos(-1);

        arc[2] = acos((b * b + c * c - a * a) / (2 * b * c));
        arc[2] = arc[2] * 180 / acos(-1);

        sort(arc, arc + 3, greater<double>());

        // cout << arc[0] << " " << arc[1] << " " << arc[2] << endl;

        double s = (a + b + c) / 2;
        double tri = s * (s - a) * (s - b) * (s - c);
        tri = sqrt(tri);

        double R1 = acos(-1.0) * r[0] * r[0];
        R1 = (R1 * arc[0]) / 360;

        double R2 = acos(-1.0) * r[1] * r[1];
        R2 = (R2 * arc[1]) / 360;

        double R3 = acos(-1.0) * r[2] * r[2];
        R3 = (R3 * arc[2]) / 360;

        cout << fixed << setprecision(6);
        cout << tri - (R1 + R2 + R3) << endl;
    }

    return 0;
}