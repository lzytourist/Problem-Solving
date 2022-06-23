#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Query {
    string class1, class2, object;
    int time{};

    Query() = default;

    Query(string c1, string c2, string obj, int _time) {
        class1 = std::move(c1);
        class2 = std::move(c2);
        object = std::move(obj);
        time = _time;
    }
};

int LOG;
vector<int> depth;
vector<vector<int>> up;

void dfs(vector<vector<int>> const &g, int u, int from) {
    depth[u] = depth[from] + (u != from);
    up[u][0] = from;

    for (int i = 1; i < LOG; ++i) {
        up[u][i] = up[up[u][i - 1]][i - 1];
    }

    for (int v : g[u]) {
        dfs(g, v, u);
    }
}

bool is_ancestor(int u, int v) {
    int k = depth[v] - depth[u];

    if (k < 0) {
        return false;
    }

    for (int i = 0; i < LOG; ++i) {
        if (k & (1 << i)) {
            v = up[v][i];
        }
    }

    return u == v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ":\n";

        int n;
        cin >> n;

        map<string, pair<int, int>> classes; // name -> {id and time}
        classes.insert({"Main", {0, -1}});

        map<string, bool> objects;
        vector<vector<int>> graph(2 * n);
        vector<Query> queries;

        auto classExists = [&](const string& name) -> bool {
            return classes.find(name) != classes.end();
        };

        for (int i = 0; i < n; ++i) {
            string input[6];
            cin >> input[0];

            if (input[0] == "+") {
                for (int j = 1; j < 5; ++j) cin >> input[j];

                int id = (int) classes.size();

                if (!classExists(input[2])) {
                    classes[input[2]] = {id, i};
                    ++id;
                }

                if (!classExists(input[4])) {
                    classes[input[4]] = {id, i};
                }

                graph[classes[input[4]].first].push_back(classes[input[2]].first);
            } else {
                for (int j = 1; j < 6; ++j) cin >> input[j];

                input[5].pop_back();
                input[5].pop_back();

                queries.emplace_back(input[1], input[5], input[2], i);
                objects[input[2]] = false;
            }
        }

        LOG = 0;
        while ((1 << LOG) <= (int) classes.size()) {
            ++LOG;
        }

        depth.resize(classes.size());
        up.assign(classes.size() + 1, vector<int>(LOG + 1));

        dfs(graph, 0, 0);

        for (Query const &query : queries) {
            if (!classExists(query.class1) || !classExists(query.class2)) {
                cout << "no\n";
                continue;
            }

            if (query.time < classes[query.class1].second || query.time < classes[query.class2].second) {
                cout << "no\n";
                continue;
            }

            if (objects[query.object]) {
                cout << "no\n";
                continue;
            }

            objects[query.object] = true;

            if (is_ancestor(classes[query.class1].first, classes[query.class2].first)) {
                cout << "yes\n";
            } else {
                cout << "no\n";
            }
        }
    }

    return 0;
}
