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

int mod;

struct Matrix {
    int matrix[2][2];

    Matrix() {
        matrix[0][0] = matrix[1][1] = 1;
        matrix[0][1] = matrix[1][0] = 0;
    }

    void scan() {
        for (int i = 0; i < 2; ++i) {
            cin >> matrix[i][0] >> matrix[i][1];
            matrix[i][0] %= mod;
            matrix[i][1] %= mod;
        }
    }

    Matrix operator*(Matrix &mat) {
        Matrix mul;

        mul.matrix[0][0] = (matrix[0][0] * mat.matrix[0][0]) % mod + (matrix[0][1] * mat.matrix[1][0]) % mod;
        mul.matrix[1][0] = (matrix[1][0] * mat.matrix[0][0]) % mod + (matrix[1][1] * mat.matrix[1][0]) % mod;
        mul.matrix[0][1] = (matrix[0][0] * mat.matrix[0][1]) % mod + (matrix[0][1] * mat.matrix[1][1]) % mod;
        mul.matrix[1][1] = (matrix[1][0] * mat.matrix[0][1]) % mod + (matrix[1][1] * mat.matrix[1][1]) % mod;

        for (int i = 0; i < 2; ++i) for (int j = 0; j < 2; ++j) {
            mul.matrix[i][j] %= mod;
        }

        return mul;
    }
};

ostream& operator<<(ostream &os, Matrix &mat) {
    for (int i = 0; i < 2; ++i) {
        os << mat.matrix[i][0] << " " << mat.matrix[i][1] << endl;
    }
    return os;
}

class SegTree {
    vector<Matrix> tree;
    int N;

    void build(int node, int l, int r) {
        if (l == r) {
            return;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = ln + 1;

        build(ln, l, m);
        build(rn, m + 1, r);

        tree[node] = tree[ln] * tree[rn];
    }

    Matrix get(int node, int l, int r, int x, int y) {
        if (l > y || r < x) {
            return tree[2 * N - 1];
        }

        if (l >= x && r <= y) {
            return tree[node];
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = ln + 1;

        Matrix r1 = get(ln, l, m, x, y);
        Matrix r2 = get(rn, m + 1, r, x, y);

        Matrix res = r1 * r2;
        return res;
    }

public:
    SegTree(int n) {
        N = 1;
        while (N < n) N <<= 1;

        tree.resize(2 * N);
        for (int i = N - 1; i < N - 1 + n; ++i) {
            tree[i].scan();
        }

        build(0, 0, N - 1);
    }

    Matrix get(int l, int r) {
        --l, --r;

        return get(0, 0, N - 1, l, r);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LUCHADOR
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int n, m;
    cin >> mod >> n >> m;

    SegTree seg(n);

    while (m--) {
        int l, r;
        cin >> l >> r;

        Matrix res = seg.get(l, r);

        cout << res << endl;
    }

    return 0;
}
