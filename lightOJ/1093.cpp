#include <iostream>
#include <vector>

using namespace std;

class MinMax {
    vector<int> mn, mx;
    int N, d;

    void update(int node, int l, int r, int const &p, int const &v) {
        if (l == r) {
            mn[node] = v;
            mx[node] = v;
            return;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        if (p <= m) {
            update(ln, l, m, p, v);
        } else {
            update(rn, m + 1, r, p, v);
        }

        mn[node] = min(mn[ln], mn[rn]);
        mx[node] = max(mx[ln], mx[rn]);
    }

public:
    explicit MinMax(int const &n) {
        N = 1;
        d = n;
        while (N < n) {
            N <<= 1;
        }

        mn.assign(2 * N, 1e9);
        mx.assign(2 * N, 0);
    }

    void update(int p, int v) {
        update(0, 0, N - 1, p, v);
    }

    int getDiff() {
        return mx[0] - mn[0];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n, d;
        cin >> n >> d;

        MinMax minMax(d);

        int mxDiff = 0;
        for (int i = 0, x, p = 0; i < n; ++i) {
            cin >> x;

            if (i < d) {
                minMax.update(i, x);
            } else {
                minMax.update(i % d, x);
            }

            mxDiff = max(mxDiff, minMax.getDiff());
        }

        cout << mxDiff << "\n";
    }

    return 0;
}
