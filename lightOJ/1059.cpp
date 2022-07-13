#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <queue>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

struct Edge {
    int u, v, c;
    
    Edge() = default;
    
    Edge(int _u, int _v, int _c) : u(_u), v(_v), c(_c) {}
    
    bool operator<(Edge const &edge) const {
        return edge.c < c;
    }
};

pair<int, int> parent[10000];

int find_set(int v) {
    if (parent[v].F == v) {
        return v;
    }
    
    return parent[v].F = find_set(parent[v].F);
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
    
    int t;
    cin >> t;
    
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";
        
        int n, m, a;
        cin >> n >> m >> a;
        
        for (int i = 0; i < n; ++i) {
            parent[i] = {i, 1};
        }
        
        int air = n * a;
        int airports = n;
        int road = 0;
        
        priority_queue<Edge> Q;
        
        for (int i = 0, u, v, c; i < m; ++i) {
            cin >> u >> v >> c;
            --u, --v;
            
            Q.push(Edge(u, v, c));
        }
        
        while (!Q.empty()) {
            Edge edge = Q.top();
            Q.pop();
            
            if (edge.c < a) {
                if (find_set(edge.u) != find_set(edge.v)) {
                    --airports;
                    road += edge.c;
                    air -= a;
                    union_set(edge.u, edge.v);
                }
            }
        }
        
        cout << road + air << " " << airports << endl;
    }
    
    return 0;
}
