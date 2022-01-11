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
    
    while (t--) {
        string a, b;
        cin >> a >> b;
        
        int n = a.length(), m = b.length();
        
        if (n < m) {
            swap(a, b);
            swap(n, m);
        }
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int carry = 0;
        string sum = "";
        
        for(int i = 0; i < m; ++i) {
            int r = (a[i] - '0') + (b[i] - '0') + carry;
            sum += (char) (r % 10 + '0');
            
            carry = r / 10;
        }
        
        for (int i = m; i < n; ++i) {
            int r = (a[i] - '0') + carry;
            sum += (r % 10 + '0');
            carry = r / 10;
        }
        
        while(carry > 0) {
            sum += (carry % 10 + '0');
            carry /= 10;
        }
        
        reverse(sum.begin(), sum.end());
        
        // cout << sum << endl;
        cout << sum[0];
        if (sum.length() > 1) {
            cout << ".";
        }
        for (int i = 1; i < min(7, (int)sum.length()); ++i) {
            cout << sum[i];
        }
        cout << "E+" << sum.length() - 1 << endl;
    }
    
    return 0;
}
