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

class SegTree {
    vector<int> tree;
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
        int rn = ln + 1;

        build(ln, l, m, a);
        build(rn, m + 1, r, a);

        tree[node] = max(tree[ln], tree[rn]);
    }

    void update(int node, int l, int r, int const &p, int const &v) {
        if (l == r) {
            tree[node] -= v;
            return;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        if (p <= m) update(ln, l, m, p, v);
        else update(rn, m + 1, r, p, v);

        tree[node] = max(tree[ln], tree[rn]);
    }

    int get(int node, int l, int r, int const &v) {
        if (tree[node] < v) {
            return -1;
        }

        if (l == r) {
            return l;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = ln + 1;

        if (tree[ln] >= v) return get(ln, l, m, v);
        return get(rn, m + 1, r, v);
    }

public:
    SegTree(int n, vector<int> const &a) {
        N = 1;
        while (N < n) N <<= 1;

        tree.assign(2 * N, 0);
        build(0, 0, N - 1, a);
    }

    void update(int p, int v) {
        update(0, 0, N - 1, p, v);
    }

    int get(int v) {
        return get(0, 0, N - 1, v);
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    scan(a);

    SegTree seg(n, a);

    while (m--) {
        int x;
        cin >> x;

        int r = seg.get(x);
        if (r == -1) {
            cout << 0;
        } else {
            cout << r + 1;
            seg.update(r, x);
        }

        cout << (m == 0 ? "\n" : " ");
    }

    return 0;
}