#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void doomed() {
  ll n, k;
  scanf("%lld%lld", &n, &k);
  
  if(k == 1) {
    puts("1");
    return;
  }
  
  ll l = 2, r = 1e18, m, x;
  while(l <= r) {
    m = l + (r - l) / 2;
    x = m / n;
    if(m - x < k) {
      l = m + 1;
    } else {
      r = m - 1;
    }
  }
  
  // printf("%lld %lld %lld\n", k, n, l);
  printf("%lld\n", l);
}

int main()
{
  // ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  int t = 1;
  scanf("%d", &t);
  // cin >> t;
  
  while(t--) {
    doomed();
  }
  
  return 0;
}
