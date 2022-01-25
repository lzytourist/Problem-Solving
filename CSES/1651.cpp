#include <iostream>
#include <vector>

using namespace std;

class XOR {
    vector<int> tree;
    int N;

    void init(int node, int l, int r, vector<int> const &a) {
        if (l == r) {
            if (l < (int) a.size()) {
                tree[node] = a[l];
            }
            return;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        init(ln, l, m, a);
        init(rn, m + 1, r, a);

        tree[node] = tree[ln] ^ tree[rn];
    }

    int getSum(int node, int l, int r, int &i, int &j) {
        if (l > j || r < i) {
            return 0;
        }

        if (l >= i && r <= j) {
            return tree[node];
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        int r1 = getSum(ln, l, m, i, j);
        int r2 = getSum(rn, m + 1, r, i, j);

        return r1 ^ r2;
    }

public:
    XOR(vector<int> const &a, int const &n) {
        N = 1;
        while(N < n) {
            N <<= 1;
        }
        tree.assign(2 * N, 0);
        init(0, 0, N - 1, a);
    }

    int getSum(int a, int b) {
        return getSum(0, 0, N - 1, a, b);
    }
};

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int &x : a) {
        cin >> x;
    }

    XOR aXor = XOR(a, n);
    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;

        cout << aXor.getSum(x, y) << "\n";
    }

    return 0;
}