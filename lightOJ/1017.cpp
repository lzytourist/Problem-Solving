#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<vector<int>> dp;

inline int get_total_dust(int s, int e, vector<pair<int, int>> const &points) {
    int total = points[e].second;
    if (s > 0) {
        total -= points[s - 1].second;
    }
    return total;
}

int clean(vector<pair<int, int>> const &points, int const &w, int p, int k) {
    if (p >= (int) points.size() || k <= 0) {
        return 0;
    }

    if (dp[p][k] != -1) {
        return dp[p][k];
    }

    int brush_size = points[p].first + w;
    int l = p, r = (int) points.size() - 1, m, upto = p;
    while (l <= r) {
        m = l + (r - l) / 2;
        if (points[m].first <= brush_size) {
            l = m + 1;
            upto = m;
        } else {
            r = m - 1;
        }
    }

    int r1 = clean(points, w, p + 1, k);
    int r2 = clean(points, w, upto + 1, k - 1) + get_total_dust(p, upto, points);

    return dp[p][k] = max(r1, r2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n, w, k;
        cin >> n >> w >> k;

        map<int, int> dust;
        for (int i = 0, x, y; i < n; ++i) {
            cin >> x >> y;
            dust[y]++;
        }

        vector<pair<int, int>> points(dust.size());
        int p = 0;
        for (pair<const int, int> &d: dust) {
            points[p] = d;

            if (p > 0) {
                points[p].second += points[p - 1].second;
            }

            ++p;
        }

        dp.assign(dust.size(), vector<int>(k + 1, -1));
        cout << clean(points, w, 0, k) << "\n";
    }

    return 0;
}
