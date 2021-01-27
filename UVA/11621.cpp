#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const ll N = 3e9;
set<ll> st;

void run(ll n) {
  if(n > N) return;
  
  if(st.count(n)) return;
  
  st.insert(n);
  
  run(n * 2);
  run(n * 3);
}

int main()
{
  ll n;
  
  run(1);
  
  while(scanf("%lld", &n) == 1) {
    if(n == 0) break;
    
    if(st.count(n)) {
      printf("%lld\n", n);
      continue;
    }
    
    auto x = st.upper_bound(n);
    printf("%lld\n", *x);
  }
  
  return 0;
}
