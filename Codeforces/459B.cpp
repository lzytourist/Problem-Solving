#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);
  vector<int> a(n);
  for(int& x : a) scanf("%d", &x);
  sort(a.begin(), a.end());
  
  int l = lower_bound(a.begin(), a.end(), a[0] + 1) - a.begin();
  if(l == n) {
    printf("0 %lld\n", (1LL * l * (l - 1)) / 2);
    return 0;
  }
  
  int r = upper_bound(a.begin(), a.end(), a[n - 1] - 1) - a.begin();
  r = n - r;
  
  // printf("%d %d\n", l, r);
  printf("%d %lld\n", a[n - 1] - a[0], 1LL * l * r);
  
  return 0;
}
