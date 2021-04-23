#include <bits/stdc++.h>
 
#define endl '\n'
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
 
using namespace std;
 
int n, x;
vector<int> a;
vector<ll> dp;
 
ll run(ll sum) {
  if(sum == x) {
    return 0;
  }
  
  if(dp[sum] != -1) return dp[sum];
    
  ll r = INT_MAX;
  for(int i = 0; i < n; ++i) {
    if(sum + a[i] <= x) {
      r = min(r, run(sum + a[i]) + 1);
    }
  }
  
  return dp[sum] = r;
}
 
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> x;
  a = vector<int>(n);
  for(int& xx : a) cin >> xx;
  
  dp = vector(x + 1, -1LL);
  
  int r = run(0);
  if(r == INT_MAX) cout << -1 << endl;
  else cout << r << endl;
  
  return 0;
}
