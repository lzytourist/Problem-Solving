#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void doomed() {
  int n;
  scanf("%d", &n);
  vector<pair<int, int>> a(n);
  for(int i = 0; i < n; ++i) {
    scanf("%d", &a[i].F);
    a[i].S = i;
  }
  sort(a.begin(), a.end());
  
  bool gone = false;
  bool ok = true;
  int x, y;
  for(int i = 0; i < n; ++i) {
    if(a[i].S != i) {
      ok = false;
      if(gone) {
        puts("no");
        return;
      }
      gone = true;
      
      x = i;
      y = i;
      while(i + 1 < n && a[i].S - a[i + 1].S == 1) {
        ++i;
      }
      y = i;
    }
  }
  
  if(ok) {
    puts("yes");
    puts("1 1");
    return;
  }
  printf("yes\n%d %d\n", x + 1, y + 1);
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  int t = 1;
  // scanf("%d", &t);
  // cin >> t;
  
  while(t--) {
    doomed();
  }
  
  return 0;
}
