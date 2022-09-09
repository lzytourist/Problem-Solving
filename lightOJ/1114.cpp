#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

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

        int n;
        cin >> n;

        map<pair<string, string>, int> dictionary;
        string s, tmp;

        for (int i = 0; i < n; ++i) {
            cin >> s;

            tmp.pb(s.front());
            tmp.pb(s.back());

            s.front() = '-';
            s.back() = '-';

            sort(s.begin(), s.end());

            dictionary[{tmp, s}]++;
            tmp.clear();
        }

        cin >> n;
        getline(cin, s);

        while (n--) {
            getline(cin, s);
            
            tmp.clear();
            int cnt = 1;

            for (int i = 0; i < (int) s.length(); ++i) {
                tmp.pb(s.at(i));

                if (s[i] == ' ') {
                    tmp.pop_back();

                    if (tmp.empty()) {
                        continue;
                    }

                    string p;
                    p.pb(tmp.front());
                    p.pb(tmp.back());

                    tmp.front() = '-';
                    tmp.back() = '-';
                    sort(tmp.begin(), tmp.end());

                    cnt *= dictionary[{p, tmp}];

                    tmp.clear();
                } else if (i + 1 == (int) s.length()) {

                    if (tmp.empty()) {
                        continue;
                    }

                    string p;
                    p.pb(tmp.front());
                    p.pb(tmp.back());

                    tmp.front() = '-';
                    tmp.back() = '-';
                    sort(tmp.begin(), tmp.end());

                    cnt *= dictionary[{p, tmp}];
                }
            }
            
            cout << cnt << endl;
        }

    }

    return 0;
}