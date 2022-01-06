#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

pair<bool, int> bfs(vector<vector<char>> const &forest, pair<int, int> start, pair<int, int> end) {
    int n = (int) forest.size();
    queue<pair<int, int>> Q;
    vector<vector<int>> lvl(n, vector<int>(n, -1));

    Q.push(start);
    lvl[start.first][start.second] = 0;

    auto ok = [&](int i, int j) -> bool {
        if (i >= 0 && j >= 0 && i < n && j < n && lvl[i][j] == -1 && forest[i][j] != '#') {
            if (forest[i][j] == '.') {
                return true;
            }
            if (i == end.first && j == end.second) {
                return true;
            }
        }
        return false;
    };

    while (!Q.empty()) {
        pair<int, int> u = Q.front();
        Q.pop();

        for (pair<int, int> side: vector<pair<int, int>>({{1,  0},
                                                          {0,  1},
                                                          {-1, 0},
                                                          {0,  -1}})) {
            int sx = side.first + u.first;
            int sy = side.second + u.second;

            if (ok(sx, sy)) {
                Q.push({sx, sy});
                lvl[sx][sy] = lvl[u.first][u.second] + 1;
            }
        }
    }

    return {lvl[end.first][end.second] != -1, lvl[end.first][end.second]};
}

void doomed() {
    int n;
    cin >> n;

    vector<vector<char>> forest(n, vector<char>(n));
    map<char, pair<int, int>> foods;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> forest[i][j];

            if (forest[i][j] >= 'A' && forest[i][j] <= 'Z') {
                foods[forest[i][j]] = {i, j};
            }
        }
    }

    pair<bool, int> dist = {true, 0};
    pair<int, int> start, end;
    for (pair<const char, pair<int, int>> const &food: foods) {
        if (food.first == 'A') {
            start = food.second;
            forest[start.first][start.second] = '.';
            continue;
        }

        end = food.second;
        pair<bool, int> res = bfs(forest, start, end);
        dist.first = res.first;
        dist.second += res.second;

        forest[end.first][end.second] = '.';

        if (!res.first) {
            break;
        }

        start = food.second;
    }

    if (dist.first) {
        cout << dist.second << "\n";
    } else {
        cout << "Impossible" << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i) {
        cout << "Case " << i << ": ";
        doomed();
    }

    return 0;
}
