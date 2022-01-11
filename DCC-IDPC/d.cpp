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
        string s;
        cin >> s;
        
        int n = s.length();
        map<int, int> m;
        
        bool palin = true;
        
        for(int i = 0; i < n / 2; ++i) {
            m[s[i]]++;
            if (s[i] != s[n - 1 - i]) {
                palin = false;
            }
            
            if(m[s[i]] > 1) {
                palin = false;
            }
         }
         
         cout << (palin ? "Yes" : "No") << endl;
    }
    
    
    return 0;
}
