#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n;
  
  while(scanf("%d", &n) == 1) {
    int p;
    vector<int> a(n);
    for(int& x : a) scanf("%d", &x);
    scanf("%d", &p);
    sort(a.begin(), a.end());
    
    pair<int, pair<int, int>> small = make_pair(INT_MAX, make_pair(0, 0));
    
    for(int i = 0; i < n; ++i) {
      if(binary_search(a.begin(), a.end(), p - a[i])) {
        int dist = abs(a[i] - (p - a[i]));
        if(small.first > dist) {
          small.first = dist;
          small.second.first = a[i];
          small.second.second = p - a[i];
        }
      }
    }
    
    printf("Peter should buy books whose prices are %d and %d.\n\n", small.second.first, small.second.second);
  }
  
  return 0;
}
