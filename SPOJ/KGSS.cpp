#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class MaxSum {
    vector<pair<int, int>> tree;
    int N;

    void init(int node, int l, int r, vector<int> const &a) {
        if (l == r) {
            if (l < (int) a.size()) {
                tree[node].first = a[l];
            }
            return;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        init(ln, l, m, a);
        init(rn, m + 1, r, a);

        vector<int> tmp = {tree[ln].first, tree[ln].second, tree[rn].first, tree[rn].second};
        sort(tmp.begin(), tmp.end(), greater<int>());

        tree[node] = {tmp[0], tmp[1]};
    }

    void update(int node, int l, int r, int &idx, int &v) {
        if (l == r) {
            tree[node].first = v;
            return;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;
        if (idx <= m) {
            update(ln, l, m, idx, v);
        } else {
            update(rn, m + 1, r, idx, v);
        }

        vector<int> tmp = {tree[ln].first, tree[ln].second, tree[rn].first, tree[rn].second};
        sort(tmp.begin(), tmp.end(), greater<int>());

        tree[node] = {tmp[0], tmp[1]};
    }

    pair<int, int> get_max(int node, int l, int r, int &x, int &y) {
        if (l > y || r < x) {
            return {0, 0};
        }

        if (l >= x && r <= y) {
            return tree[node];
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        pair<int, int> s1 = get_max(ln, l, m, x, y);
        pair<int, int> s2 = get_max(rn, m + 1, r, x, y);

        vector<int> tmp = {s1.first, s1.second, s2.first, s2.second};
        sort(tmp.begin(), tmp.end(), greater<int>());

        return {tmp[0], tmp[1]};
    }

public:
    MaxSum(int n, vector<int> const &a) {
        N = 1;
        while (N < n) {
            N <<= 1;
        }
        tree.assign(2 * N, {0, 0});
        init(0, 0, N - 1, a);
    }

    void update(int i, int v) {
        update(0, 0, N - 1, i, v);
    }

    int get_max_sum(int x, int y) {
        pair<int, int> s = get_max(0, 0, N - 1, x, y);
        return s.first + s.second;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x: a) {
        cin >> x;
    }

    MaxSum maxSum = MaxSum(n, a);

    int q;
    cin >> q;

    while (q--) {
        char c;
        cin >> c;

        if (c == 'U') {
            int i, v;
            cin >> i >> v;
            --i;
            maxSum.update(i, v);
        } else {
            int x, y;
            cin >> x >> y;
            --x, --y;

            cout << maxSum.get_max_sum(x, y) << "\n";
        }
    }

    return 0;
}
