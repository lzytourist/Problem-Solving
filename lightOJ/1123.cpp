#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Trail {
    int u, v, w;

    Trail() = default;

    Trail(int _u, int _v, int _w) {
        u = _u;
        v = _v;
        w = _w;
    }

    bool operator <(Trail const &trail) const {
        return trail.w < w;
    }
};

const int N = 2e2 + 1;
pair<int, int> parent[N];

int find_set(int v) {
    return parent[v].F = (parent[v].F == v ? v : find_set(parent[v].F));
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

int get_mst(priority_queue<Trail> Q, int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = {i, 1};
    }

    int mst = 0, mx_size = 0;
    while (!Q.empty() && mx_size < n) {
        Trail trail = Q.top();
        Q.pop();

        int a = find_set(trail.u);
        int b = find_set(trail.v);

        if (a != b) {
            union_set(a, b);
            mst += trail.w;
        }

        mx_size = max({
            mx_size, 
            parent[find_set(trail.u)].S, 
            parent[find_set(trail.v)].S}
        );
    }

    return mx_size == n ? mst : -1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    #ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in.txt", "r", stdin);
    freopen("/home/joker/Documents/code/out.txt", "w", stdout);
    #endif

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ":\n";

        int n, w;
        cin >> n >> w;

        priority_queue<Trail> Q;

        for (int i = 0, u, v, c; i < w; ++i) {
            cin >> u >> v >> c;

            Q.push(Trail(u, v, c));
            
            cout << get_mst(Q, n) << endl;
        }
    }

    return 0;
}