#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;

const int N = 8e7 + 6e6 + 3e4;
vector<int> primes;

void gen() {
  bitset<N> *prime;
  prime = (bitset<N> *)malloc(sizeof(bitset<N>));
  
  for(int i = 3; 1LL * i * i <= 1LL * N; i += 2) {
    if(!(*prime)[i]) {
      for(ll j = 1LL * i * i; j < N; j += 2 * i) {
        (*prime)[j] = 1;
      }
    }
  }
    
  primes.push_back(2);
  for(int i = 3; i < N; i += 2) {
    if(!(*prime)[i]) primes.push_back(i);
  }
  
  free(prime);
}

void doomed() {
  
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  gen();
  
  int t, k;
  cin >> t;
  
  while(t--) {
    cin >> k;
    cout << primes[k - 1] << endl;
  }
  
  return 0;
}
