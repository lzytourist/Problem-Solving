#include <iostream>
#include <vector>

using namespace std;

int n, q;
vector<int> tree;

void init(vector<int>const& a, int node, int l, int r) {
    if (l >= r) {
        tree[node] = a[l];
        return;
    }

    int m = l + (r - l) / 2;
    init(a, node * 2, l, m);
    init(a, node * 2 + 1, m + 1, r);

    tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}

void init(vector<int>const& a) {
    int x = 1;
    while (x < n) {
        x <<= 1;
    }
    tree.resize(2 * x + 1);
    init(a, 1, 1, n);
}

int query(int node, int l, int r, int& i, int& j) {
    if (l > j || r < i) {
        return 1e9;
    }

    if (l >= i && r <= j) {
        return tree[node];
    }

    int m = l + (r - l) / 2;
    int r1 = query(node * 2, l, m, i, j);
    int r2 = query(node * 2 + 1, m + 1, r, i, j);

    return min(r1, r2);
}

int query(int i, int j) {
    return query(1, 1, n, i, j);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ":\n";

        cin >> n >> q;
        vector<int> a(n + 1);

        for (int j = 1; j <= n; ++j) {
            cin >> a[j];
        }

        init(a);

        while (q--) {
            int x, y;
            cin >> x >> y;

            cout << query(x, y) << "\n";
        }
    }

    return 0;
}
