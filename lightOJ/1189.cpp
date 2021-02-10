#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

map<ll, vector<int>> comb;

void doomed() {
  ll n;
  scanf("%lld", &n);
  
  vector<int> nums = comb[n];
  int sz = nums.size();
  
  if(sz == 0) {
    nums = comb[n - 1];
    sz = nums.size();
    if(sz) printf("0!+");
  }
  
  if(sz == 0) {
    puts("impossible");
    return;
  }
  
  for(int i = 0; i < sz; ++i) {
    printf("%d!", nums[i] + 1);
    if(i < sz - 1) printf("+");
    else puts("");
  }
}

int main()
{
  // ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  const int N = 19;
  vector<ll> factorial(N);
  factorial[0] = 1;
  
  for(int i = 1; i < N; ++i) {
    factorial[i] = factorial[i - 1] * (i + 1);
  }
  
  int n = 1 << N;
  for(int i = 0; i <= n; ++i) {
    ll sum = 0LL;
    vector<int> nums;
    for(int j = 0; j < N; ++j) {
      if(i & (1 << j)) {
        sum += factorial[j];
        nums.push_back(j);
      }
    }
    comb[sum] = nums;
  }
    
  int t;
  scanf("%d", &t);
  // cin >> t;
  
  for(int i = 1; i <= t; ++i) {
    printf("Case %d: ", i);
    // cout << "Case " << i << ": ";
    doomed();
  }
  
  return 0;
}
