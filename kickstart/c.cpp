#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 1e9 + 8;
vector<ll> product;

void gen() {
  bitset<N> prime;
    
  for(int i = 3; 1LL * i * i <= 1LL * N; i += 2) {
    if(!prime[i]) {
      for(ll j = 1LL * i * i; j < 1LL * N; j += 2 * i) {
        prime[j] = 1;
      }
    }
  }
  
  int prev = 2;
  for(int i = 3; i < N; i += 2) {
    if(!prime[i]) {
      product.push_back(1LL * prev * i);
      prev = i;
    }
  }
  
  // sort(product.begin(), product.end());
}

void doomed() {
  ll n;
  cin >> n;
  
  if(binary_search(product.begin(), product.end(), n)) {
    cout << n << endl;
  } else {
    auto it = lower_bound(product.begin(), product.end(), n);
    --it;
    cout << *it << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  gen();
  
  int t;
  cin >> t;
  
  for(int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    doomed();
  }
  
  return 0;
}
