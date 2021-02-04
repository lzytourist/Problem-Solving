#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

vector<int> primes;
bitset<1001> prime;

vector<pair<int, int>> factorize(int n) {
  int sz = primes.size();
  vector<pair<int, int>> factors;
  
  for(int i = 0; i < sz && primes[i] <= n; ++i) {
    if(n % primes[i] == 0) {
      int cnt = 0;
      
      while(n % primes[i] == 0) {
        ++cnt;
        n /= primes[i];
      }
      
      factors.push_back({primes[i], cnt});
    }
  }
  
  return factors;
}

int main()
{
  // ios_base::sync_with_stdio(false), cin.tie(nullptr);
  
  vector<pair<int, int>> fib(41);
  fib[0] = {1, 0};
  fib[1] = {0, 1};
  
  for(int i = 2; i < 41; ++i) {
    fib[i].F = fib[i - 1].F + fib[i - 2].F;
    fib[i].S = fib[i - 1].S + fib[i - 2].S;
  }
  
  for(int i = 2; i < 1001; ++i) {
    if(!prime[i]) {
      primes.push_back(i);
      for(int j = i * i; j < 1001; j += i) {
        prime[j] = 1;
      }
    }
  }
    
  int t;
  scanf("%d", &t);
  
  while(t--) {
    int a, b, n;
    scanf("%d%d%d", &n, &a, &b);
    
    map<int, long> m;
    for(pair<int, int> x : factorize(a)) {
      m[x.F] += x.S * fib[n].F;
    }
    
    for(pair<int, int> x : factorize(b)) {
      m[x.F] += x.S * fib[n].S;
    }
    
    for(pair<int, int> x : m) {
      printf("%d %d\n", x.F, x.S);
    }
    puts("");
  }
  
  return 0;
}
