#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SegTree {
    vector<int> tree, lazy;
    int N;

    void update(int node, int l, int r, int &x, int &y, int &v) {
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        if (lazy[node] != -1) {
            tree[node] = (r - l + 1) * lazy[node];

            if (l != r) {
                lazy[ln] = lazy[node];
                lazy[rn] = lazy[node];
            }

            lazy[node] = -1;
        }

        if (l > y || r < x) return;

        if (l >= x && r <= y) {
            tree[node] = (r - l + 1) * v;

            if (l != r) {
                lazy[ln] = v;
                lazy[rn] = v;
            }

            return;
        }

        int m = l + (r - l) / 2;
        update(ln, l, m, x, y, v);
        update(rn, m + 1, r, x, y, v);

        tree[node] = tree[ln] + tree[rn];
    }

    int get(int node, int l, int r, int &x, int &y) {
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        if (lazy[node] != -1) {
            tree[node] = (r - l + 1) * lazy[node];

            if (l != r) {
                lazy[ln] = lazy[node];
                lazy[rn] = lazy[node];
            }

            lazy[node] = -1;
        }

        if (l > y || r < x) return 0;

        if (l >= x && r <= y) return tree[node];

        int m = l + (r - l) / 2;
        int r1 = get(ln, l, m, x, y);
        int r2 = get(rn, m + 1, r, x, y);

        return r1 + r2;
    }

public:
    explicit SegTree(int n) {
        N = 1;
        while (N < n) {
            N <<= 1;
        }

        tree.assign(2 * N, 0);
        lazy.assign(2 * N, -1);
    }

    void update(int x, int y, int v) {
        update(0, 0, N - 1, x, y, v);
    }

    int get(int x, int y) {
        return get(0, 0, N - 1, x, y);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ":\n";

        int n, q;
        cin >> n >> q;

        SegTree segTree(n);
        while (q--) {
            int c, x, y;
            cin >> c >> x >> y;

            if (c == 1) {
                int v;
                cin >> v;

                segTree.update(x, y, v);
            } else {
                int r = segTree.get(x, y);
                int d = y - x + 1;

                if (r % d == 0) {
                    cout << r / d << endl;
                    continue;
                }

                int g = __gcd(r, d);
                cout << r / g << "/" << d / g << endl;
            }
        }
    }

    return 0;
}
