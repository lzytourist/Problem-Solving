#include <iostream>
#include <vector>

typedef long long ll;

using namespace std;

class Segment {
    vector<ll> tree, lazy;
    int N{};

    void set(int node, int l, int r, int &x, int &y, int &v) {
        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node];

            if (l != r) {
                lazy[(node << 1) + 1] += lazy[node];
                lazy[(node << 1) + 2] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (l > y || r < x) {
            return;
        }

        if (l >= x && r <= y) {
            tree[node] += (r - l + 1) * v;

            if (l != r) {
                lazy[(node << 1) + 1] += v;
                lazy[(node << 1) + 2] += v;
            }
            return;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        set(ln, l, m, x, y, v);
        set(rn, m + 1, r, x, y, v);

        tree[node] = tree[ln] + tree[rn];
    }

    ll sum(int node, int l, int r, int &x, int &y) {
        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node];
            if (l != r) {
                lazy[(node << 1) + 1] += lazy[node];
                lazy[(node << 1) + 2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if (l > y || r < x) {
            return 0;
        }

        if (l >= x && r <= y) {
            return tree[node];
        }

        int m = l + (r - l) / 2;
        ll sn = sum((node << 1) + 1, l, m, x, y);
        ll sr = sum((node << 1) + 2, m + 1, r, x, y);

        return sn + sr;
    }

public:
    Segment(int n) {
        N = 1;
        while (N < n) {
            N <<= 1;
        }
        tree.assign(2 * N, 0);
        lazy.assign(2 * N, 0);
    }

    void set(int x, int y, int v) {
        set(0, 0, N - 1, x, y, v);
    }

    ll sum(int x, int y) {
        return sum(0, 0, N - 1, x, y);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        int n, q;
        cin >> n >> q;

        Segment segment = Segment(n);
        cout << "Case " << i << ":\n";
        while (q--) {

            int c;
            cin >> c;

            if (c == 0) {
                int x, y, v;
                cin >> x >> y >> v;
                segment.set(x, y, v);
            } else {
                int x, y;
                cin >> x >> y;

                cout << segment.sum(x, y) << "\n";
            }
        }
    }

    return 0;
}
