#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

pair<int, int> parent[1000];

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
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i) {
        parent[i] = {i, 1};
    }
    
    int comp = n;
    vector<pair<int, int>> stop;
    
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        --u, --v;
        
        if (find_set(u) != find_set(v)) {
            union_set(u, v);
            --comp;
        } else {
            stop.emplace_back(u, v);
        }
    }
    
    --comp;
    cout << comp << endl;
    
    if (comp > 0) {
        set<int> st;
        
        for (int i = 0; i < n; ++i) {
            st.insert(find_set(i));
        }
        
        vector<int> road;
        for (int x : st) road.push_back(x + 1);
        
        n = road.size();
        for (int i = 1; i < n; ++i) {
            cout << stop.back().F + 1 << " " << stop.back().S + 1 << " " << road[i] << " " << road[i - 1] << endl;
            stop.pop_back();
        }
    }
    
    return 0;
}
