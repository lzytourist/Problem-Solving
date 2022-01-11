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
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        if(n % m == 0) {
            int f = n / 5;
            int s = n % 5;
            
            cout << f << " " << s << endl;
        } else {
            cout << -1 << endl;
        }
    }
    
    
    return 0;
}
