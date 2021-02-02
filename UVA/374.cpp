#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll power(ll b, ll p, ll m) {
  if(p == 0) return 1;
  if(p == 1) return b;
  
  if(p & 1) return ((b % m) * (power(b, p - 1, m) % m)) % m;
  ll x = power(b, p / 2, m) % m;
  return (x * x) % m;
}

int main()
{
  ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  ll b, p, m;
  while(scanf("%lld%lld%lld", &b, &p, &m) == 3) {
    printf("%lld\n", power(b, p, m) % m);
  }
  
  return 0;
}
