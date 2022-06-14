#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int find_set(vector<int> &parent, int v) {
    if (v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent, parent[v]);
}

void union_sets(vector<int> &parent, int a, int b) {
    a = find_set(parent, a);
    b = find_set(parent, b);

    if (a != b) {
        parent[b] = a;
    }
}

struct Road {
    int u, v, cost;

    Road() = default;

    Road(int _u, int _v, int _cost) : u(_u), v(_v), cost(_cost) {}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n;
        cin >> n;


        map<string, int> cities;
        vector<Road> roads;

        for (int i = 0, cost, city = 0; i < n; ++i) {
            string c1, c2;
            cin >> c1 >> c2 >> cost;

            if (cities.find(c1) == cities.end()) {
                cities[c1] = city++;
            }
            if (cities.find(c2) == cities.end()) {
                cities[c2] = city++;
            }

            roads.emplace_back(cities[c1], cities[c2], cost);
        }

        sort(roads.begin(), roads.end(), [&](Road const &a, Road const &b) -> bool {
            return a.cost > b.cost;
        });

        vector<int> parent(cities.size());
        for (int i = 0; i < cities.size(); ++i) parent[i] = i;


        int mst = 0, e = 0;
        bool ok = true;

        while (e < (int) cities.size() - 1) {
            if (roads.empty()) {
                ok = false;
                cout << "Impossible\n";
                break;
            }

            Road road = roads.back();
            roads.pop_back();

            int a = find_set(parent, road.u);
            int b = find_set(parent, road.v);

            if (a != b) {
                ++e;
                mst += road.cost;
                union_sets(parent, a, b);
            }
        }

        if (ok)
            cout << mst << "\n";
    }

    return 0;
}
