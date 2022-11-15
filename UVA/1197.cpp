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

const int N = 30000;
pair<int, int> parent[N];

int find_set(int v) {
    if (parent[v].F == v) {
        return v;
    }
    return (parent[v].F = find_set(parent[v].F));
}

void union_set(int a, int b) {
    a = find_set(a);
    b = find_set(b);

    if (a != b) {
        if (parent[a].S < parent[b].S) {
            swap(a, b);
        }

        parent[b].F = a;
        parent[a].S += parent[b].S;
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

    int n, m;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; ++i) {
            parent[i] = {i, 1};
        }

        while (m--) {
            int group_size;
            cin >> group_size;

            --group_size;
            
            int p, x;
            cin >> p;

            while (group_size--) {
                cin >> x;

                union_set(p, x);
            }
        }

        int suspect = 0;
        int main_suspect = find_set(0);
        for (int i = 0; i < n; ++i) {
            if (find_set(i) == main_suspect) {
                ++suspect;
            }
        }

        cout << suspect << endl;
    }

    return 0;
}