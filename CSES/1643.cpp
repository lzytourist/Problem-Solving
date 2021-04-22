#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int n;
  cin >> n;
  vector<ll> a(n);
  for(ll& x : a) cin >> x;
  
  ll mx = LONG_LONG_MIN, sum = 0LL;
  for(int i = 0; i < n; ++i) {
    sum += a[i];
    mx = max(sum, mx);
    
    sum = max(0LL, sum);
  }
  
  cout << mx << endl;
  
  return 0;
}
