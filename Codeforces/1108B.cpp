#include <bits/stdc++.h>

#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void doomed() {
  int n;
  scanf("%d", &n);
  
  map<int, int> divs;
  int mx = -1;
  for(int i = 0, x; i < n; ++i) {
    scanf("%d", &x);
    divs[x]++;
    mx = max(mx, x);
  }
  
  divs[1]--;
  if(mx > 1) divs[mx]--;
  
  for(ll i = 2; i * i <= (ll)mx; ++i) {
    if(mx % i == 0) {
      divs[i]--;
      if(mx / i != i) divs[mx / i]--;
    }
  }
  
  for(auto it = divs.rbegin(); it != divs.rend(); ++it) {
    if(it->S > 0) {
      printf("%d %d\n", it->F, mx);
      return;
    }
  }
}

int main()
{
  // ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  int t = 1;
  // scanf("%d", &t);
  // cin >> t;
  
  while(t--) {
    doomed();
  }
  
  return 0;
}
