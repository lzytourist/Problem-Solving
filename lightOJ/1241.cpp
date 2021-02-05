#include <cstdio>
#include <vector>

int main()
{
  int t;
  scanf("%d", &t);
  
  for(int k = 1; k <= t; ++k) {
    int n;
    scanf("%d", &n);

    std::vector<int> a(n);
    for(int i = 0; i < n; ++i) {
      scanf("%d", &a[i]);
    }
    
    std::vector<int> dif(n);
    dif[0] = a[0] - 2;
    for(int i = 1; i < n; ++i) {
      dif[i] = a[i] - a[i - 1];
    }
    
    int lies = 0;
    for(int i = 0; i < n; ++i) {
      lies += dif[i] / 5 + (dif[i] % 5 ? 1 : 0);
    }
    
    printf("Case %d: %d\n", k, lies);
  }
  
  return 0;
}
