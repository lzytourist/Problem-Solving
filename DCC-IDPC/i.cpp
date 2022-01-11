#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    int tc = 1;
    
    while(t--) {
        cout << "Case #" << tc++ << "\n";
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for(int& x : a) {
            cin >> x;
        }
        
        vector<vector<int>> divs(100001);
        for (int i = 0; i < n; ++i) {
            for(int j = 1; 1LL * j * j <= 1LL * a[i]; ++j) {
                if (a[i] % j == 0) {
                    divs[j].push_back(i);
                    if(a[i] / j != j) {
                        divs[a[i] / j].push_back(i);
                    }
                }
            }
        }
        
        
        
        for (int i = 0; i < q; ++i) {
            int d, x, y;
            cin >> d >> x >> y;
            --x, --y;
            
            if(x > y) {
                swap(x, y);
            }
            
            int l = 0, r = divs[d].size() - 1, m, xx = -1;
            while (l <= r) {
                m = l + (r - l) / 2;
                if (divs[d][m] >= x) {
                    xx = m;
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            
            l = 0, r = divs[d].size() - 1;
            int yy = -1;
            
            while (l <= r) {
                m = l + (r - l) / 2;
                if (divs[d][m] <= y) {
                    yy = m;
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
            
            if (xx == -1 || yy == -1) {
                cout << 0 << endl;
                continue;
            }
            
            int sum = 0;
            for (; xx <= yy; ++xx) {
                sum += a[divs[d][xx]];
            }
            
            cout << sum << endl;
        }
        cout << endl;
    }
    
    
    return 0;
}
