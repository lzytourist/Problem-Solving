#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e5 + 1;
bitset<N> prime;
vector<int> primes;

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
  
  for(int i = 2; i < N; ++i) {
    if(!prime[i]) {
      primes.push_back(i);
      for(ll j = 1LL * i * i; j < (ll)N; j += i) {
        prime[j] = 1;
      }
    }
  }
  
  int t;
  scanf("%d", &t);
  
  while(t--) {
    int n;
    scanf("%d", &n);
    
    int neg = 0;
    for(pair<int, int> x : factorize(n)) {
      if((x.F - 1) % 4 == 0) neg += x.S;
    }
    
    puts(neg & 1 ? "-" : "+");
  }
  
  return 0;
}
