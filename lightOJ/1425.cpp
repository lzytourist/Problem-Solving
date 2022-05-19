#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <stack>

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
    
    int t;
    cin >> t;
    
    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";
        
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int &x : a) cin >> x;
        
        auto can = [&](int k) -> bool {
            int now = 0;
            
            for (int i = 0; i < n; ++i) {
                if (now + k < a[i]) {
                    return false;
                }
                
                if (now + k == a[i]) {
                    --k;
                }
                
                now = a[i];
            }
            
            return true;
        };
        
        int l = 0, r = 1e9, m, p = -1;
        while (l <= r) {
            m = l + (r - l) / 2;
            
            if (can(m)) {
                r = m - 1;
                p = m;
            } else {
                l = m + 1;
            }
        }
        
        cout << p << endl;
    }
    
    return 0;
}
