#include <iostream>
#include <vector>

struct Army {
    int status, id;

    Army() = default;

    Army(int _status, int _id) : status(_status), id(_id) {}
};

class SegTree {
    std::vector<Army> tree;
    int N;

    void build(int node, int l, int r, std::vector<int> const &a) {
        if (l == r) {
            if (l < (int) a.size()) {
                tree[node] = Army(1, a[l]);
            }
            return;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        build(ln, l, m, a);
        build(rn, m + 1, r, a);

        tree[node].status = tree[ln].status + tree[rn].status;
    }

    void update(int node, int l, int r, int const &p, int status, int const &id) {
        if (l == r) {
            tree[node] = Army(status, id);
            return;
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        if (p <= m) update(ln, l, m, p, status, id);
        else update(rn, m + 1, r, p, status, id);

        tree[node].status = tree[ln].status + tree[rn].status;
    }

    std::pair<int, int> get(int node, int l, int r, int k) {
        if (l == r) {
            return {l, tree[node].id};
        }

        int m = l + (r - l) / 2;
        int ln = (node << 1) + 1;
        int rn = (node << 1) + 2;

        if (tree[ln].status >= k) {
            return get(ln, l, m, k);
        }
        return get(rn, m + 1, r, k - tree[ln].status);
    }

public:
    explicit SegTree(int n, std::vector<int> const &a) {
        N = 1;
        while (N < n) {
            N <<= 1;
        }

        tree.assign(2 * N, Army(0, 0));
        build(0, 0, N - 1, a);
    }

    void add(int p, int id) {
        update(0, 0, N - 1, p, 1, id);
    }

    void remove(int p) {
        update(0, 0, N - 1, p, 0, -1);
    }

    int get(int k) {
        if (tree[0].status < k) {
            return -1;
        }

        std::pair<int, int> r = get(0, 0, N - 1, k);
        remove(r.first);

        return r.second;
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        std::cout << "Case " << tc << ":\n";

        int n, q;
        std::cin >> n >> q;

        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        SegTree seg(n + 50000, a);
        while (q--) {
            char c;
            int k;
            std::cin >> c >> k;

            if (c == 'a') {
                seg.add(n, k);
                ++n;
            } else {
                int r = seg.get(k);

                if (r == -1) {
                    std::cout << "none\n";
                } else {
                    std::cout << r << "\n";
                }
            }
        }
    }

    return 0;
}