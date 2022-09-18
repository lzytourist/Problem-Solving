#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int zero, one, two;

    Node() = default;

    Node(int _z, int _o, int _t) : zero(_z), one(_o), two(_t) {}

    void update(int times) {
        for (int i = 0; i < times; ++i) {
            swap(zero, two);
            swap(two, one);
        }
    }
};

class SegTree {
    vector<Node> tree;
    vector<int> lazy;
    int N;

    void build(int node, int l, int r) {
        if (l == r) {
            return;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        build(ln, l, m);
        build(rn, m + 1, r);

        tree[node].zero = tree[ln].zero + tree[rn].zero;
        tree[node].one = tree[ln].one + tree[rn].one;
        tree[node].two = tree[ln].two + tree[rn].two;
    }

    void update(int node, int l, int r, int &x, int &y) {
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        if (lazy[node] != 0) {
            tree[node].update(lazy[node] % 3);

            if (l != r) {
                lazy[ln] += lazy[node];
                lazy[rn] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (l > y || r < x) {
            return;
        }

        if (x <= l && r <= y) {
            tree[node].update(1);

            if (l != r) {
                lazy[ln] += 1;
                lazy[rn] += 1;
            }

            return;
        }

        int m = l + (r - l) / 2;
        update(ln, l, m, x, y);
        update(rn, m + 1, r, x, y);

        tree[node].zero = tree[ln].zero + tree[rn].zero;
        tree[node].one = tree[ln].one + tree[rn].one;
        tree[node].two = tree[ln].two + tree[rn].two;
    }

    int get(int node, int l, int r, int &x, int &y) {
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        if (lazy[node] != 0) {
            tree[node].update(lazy[node] % 3);

            if (l != r) {
                lazy[ln] += lazy[node];
                lazy[rn] += lazy[node];
            }

            lazy[node] = 0;
        }

        if (l > y || r < x) {
            return 0;
        }

        if (l >= x && r <= y) {
            return tree[node].zero;
        }

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
        tree.assign(2 * N, Node(1, 0, 0));
        lazy.assign(2 * N, 0);

        build(0, 0, N - 1);
    }

    void update(int x, int y) {
        update(0, 0, N - 1, x, y);
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

            if (c != 1) {
                segTree.update(x, y);
            } else {
                cout << segTree.get(x, y) << "\n";
            }
        }
    }

    return 0;
}