#include <iostream>
#include <vector>

using namespace std;

class SegmentTree {
    vector<long long> tree;
    int N;

    void set(int node, int l, int r, int &p, int &v) {
        if (r - l == 1) {
            tree[node] = v;
            return;
        }

        int m = l + (r - l) / 2;
        int ln = 2 * node + 1;
        int rn = 2 * node + 2;

        if (p < m) {
            set(ln, l, m, p, v);
        } else {
            set(rn, m, r, p, v);
        }

        tree[node] = tree[ln] + tree[rn];
    }

    long long sum(int node, int l, int r, int &i, int &j) {
        if (l >= j || r <= i) {
            return 0;
        }

        if (l >= i && r <= j) {
            return tree[node];
        }

        int m = l + (r - l) / 2;
        long long s1 = sum(2 * node + 1, l, m, i, j);
        long long s2 = sum(2 * node + 2, m, r, i, j);

        return s1 + s2;
    }

public:
    SegmentTree(int n) {
        N = 1;
        while (N < n) {
            N <<= 1;
        }
        tree.assign(2 * N, 0LL);
    }

    void set(int p, int v) {
        set(0, 0, N, p, v);
    }

    long long sum(int i, int j) {
        return sum(0, 0, N, i, j);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    SegmentTree segmentTree = SegmentTree(n);
    for (int i = 0, x; i < n; ++i) {
        cin >> x;
        segmentTree.set(i, x);
    }

    while (q--) {
        int c;
        cin >> c;

        if (c == 1) {
            int k, u;
            cin >> k >> u;

            --k;
            segmentTree.set(k, u);
        } else {
            int a, b;
            cin >> a >> b;
            --a;
            cout << segmentTree.sum(a, b) << "\n";
        }
    }

    return 0;
}
