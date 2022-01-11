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
    
    int n, q;
    cin >> n;
    
    vector<int> a(n);
    for(int& x : a) cin >> x;
    
    cin >> q;
    
    while(q--) {
        int age;
        cin >> age;
        
        int l = 0, r = n - 1, m, p = -1;
        while (l <= r) {
            m = l + (r - l) / 2;
            if (a[m] < age) {
                p = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        
        cout << p + 1 << endl;
    }
    
    return 0;
}
