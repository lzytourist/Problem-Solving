#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int M = 1e9 + 7;

int n, x;
vector<int> a;
vector<int> dp;

int run(int sum) {
  if(sum == 0) {
    return 1;
  }
  
  if(dp[sum] != -1) return dp[sum];
  
  int cnt = 0;
  for(int i = 0; i < n; ++i) {
    if(sum - a[i] >= 0) {
      int r = run(sum - a[i]);
      cnt = (cnt + r) % M;
    }
  }
  
  return dp[sum] = cnt;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  cin >> n >> x;
  a = vector<int>(n);
  for(int& xx : a) cin >> xx;
  
  dp = vector(x + 1, -1);
  cout << run(x) << endl;
  
  return 0;
}
