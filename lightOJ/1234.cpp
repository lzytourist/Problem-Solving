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

const int N = 1e2;
const double EULER_CONSTANT = 0.57721566490153286060;
double h[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LUCHADOR
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    for (int i = 1; i < N; ++i) {
        h[i] = h[i - 1] + (1.0 / i);
    }

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n;
        cin >> n;

        cout << fixed << setprecision(10);

        if (n < N) {
            cout << h[n] << endl;
        } else {
            double r = EULER_CONSTANT + log(n) + (1.0 / (2 * n));
            cout << r << endl;
        }
    }

    return 0;
}