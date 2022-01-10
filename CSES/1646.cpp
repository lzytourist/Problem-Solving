#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];

        if (i > 0) {
            a[i] += a[i - 1];
        }
    }

    while (q--) {
        int x, y;
        cin >> x >> y;
        --x, --y;

        long long sum = a[y];
        if (x != 0) {
            sum -= a[x - 1];
        }

        cout << sum << "\n";
    }

    return 0;
}
