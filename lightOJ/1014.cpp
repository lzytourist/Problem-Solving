#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void doomed() {
  int p, l, q;
  scanf("%d%d", &p, &l);
  
  q = p - l;
  if(q <= l) {
    puts("impossible");
    return;
  }
  
  vector<int> divs;
  for(ll i = 1; i * i <= (ll)q; ++i) {
    if(q % i == 0) {
      divs.push_back(i);
      if(q / i != i) divs.push_back(q / i);
    }
  }
  
  sort(divs.begin(), divs.end());
  for(int i = 0; i < (int)divs.size(); ++i) {
    if(divs[i] > l) {
      printf("%d", divs[i]);
      if(i < (int)divs.size() - 1) printf(" ");
      else puts("");
    }
  }
}

int main()
{
  // ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
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
