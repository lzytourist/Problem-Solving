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
    
    ll n, m;
    cin >> n >> m;
    
    ll sum = ((n * n) * ((n + 1) * (n + 1))) / 4;
    sum += (n + 1) * (n + 1);
    
    ll s = (m * (m + 1)) / 2;
    ll sn = ((n + 1) * (n + 2)) / 2;
    

    sum += s - sn;
    cout << sum << endl;
    
    return 0;
}
