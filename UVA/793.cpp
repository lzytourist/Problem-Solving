#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

#define MULTI int _T; cin >> _T; while (_T--)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

template <typename T>
void scan(vector<T> &v) {for(T &x : v) {cin >> x;}}

int find_set(vector<pair<int, int>> &par, int v) {
    if (v == par[v].F) return v;
    return par[v].F = find_set(par, par[v].F);
}

void union_set(vector<pair<int, int>> &par, int a, int b) {
    a = find_set(par, a);
    b = find_set(par, b);

    if (a != b) {
        if (par[a].S < par[b].S) swap(a, b);

        par[b].F = a;
        par[a].S += par[b].S;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    int t;
    cin >> t;

    string s;
    getline(cin, s);
    getline(cin, s);

    auto get_num = [&]() -> int {
        int N = 0, b = 1;
        while (!s.empty() && s.back() != ' ') {
            N = b * (s.back() - '0') + N;
            s.pop_back();
            b *= 10;
        }
        return N;
    };

    for (int tc = 0; tc < t; ++tc) {
        getline(cin, s);
        int n = get_num();

        vector<pair<int, int>> par(n);
        for (int i = 0; i < n; ++i) {
            par[i] = {i, 1};
        }

        int success = 0, error = 0;
        while (getline(cin, s)) {
            if (s == "") break;
            
            int y = get_num(); s.pop_back();
            int x = get_num();

            --x, --y;

            if (s.front() == 'c') {
                union_set(par, x, y);
            } else {
                if (find_set(par, x) == find_set(par, y)) {
                    ++success;
                } else {
                    ++error;
                }
            }
        }

        if (tc != 0) {
            cout << endl;
        }

        cout << success << "," << error << endl;
    }

    return 0;
}