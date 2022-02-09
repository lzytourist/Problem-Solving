#include <iostream>
#include <vector>

typedef unsigned long long ull;

using namespace std;

class Segment {
    vector<ull> tree, lazy;
    int N;

    void build(int node, int l, int r, vector<int> const &a) {
        if (l == r) {
            if (l < (int) a.size()) {
                tree[node] = a[l];
            }
            return;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        build(ln, l, m, a);
        build(rn, m + 1, r, a);

        tree[node] = tree[ln] + tree[rn];
    }

    void set(int node, int l, int r, int &i, int &j, int &v) {
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node];

            if (l != r) {
                lazy[ln] += lazy[node];
                lazy[rn] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (l > j || r < i) {
            return;
        }

        if (l >= i && r <= j) {
            tree[node] += (r - l + 1) * v;

            if (l != r) {
                lazy[ln] += v;
                lazy[rn] += v;
            }

            return;
        }

        int m = l + (r - l) / 2;
        set(ln, l, m, i, j, v);
        set(rn, m + 1, r, i, j, v);

        tree[node] = tree[ln] + tree[rn];
    }

    ull get(int node, int l, int r, int &i) {
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        if (lazy[node] != 0) {
            tree[node] += (r - l + 1) * lazy[node];

            if (l != r) {
                lazy[ln] += lazy[node];
                lazy[rn] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (l > i || r < i) {
            return 0;
        }

        if (l >= i && r <= i) {
            return tree[node];
        }

        int m = l + (r - l) / 2;
        ull r1 = 0;

        if (i <= m) {
            r1 = get(ln, l, m, i);
        } else {
            r1 = get(rn, m + 1, r, i);
        }

        return r1;
    }

public:
    Segment(vector<int> const &a, int n) {
        N = 1;
        while (N < n) {
            N <<= 1;
        }
        tree.assign(2 * N, 0);
        lazy.assign(2 * N, 0);

        build(0, 0, N - 1, a);
    }

    void set(int x, int y, int v) {
        set(0, 0, N - 1, x, y, v);
    }

    ull get(int k) {
        return get(0, 0, N - 1, k);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    Segment segment(a, n);
    while (q--) {
        int c;
        cin >> c;

        if (c == 1) {
            int x, y, u;
            cin >> x >> y >> u;
            --x, --y;

            segment.set(x, y, u);
        } else {
            int i;
            cin >> i;

            --i;
            cout << segment.get(i) << "\n";
        }
    }

    return 0;
}
