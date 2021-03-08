#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

bool check(int dif, vector<int>& a) {
  int n = a.size();
  
  for(int i = 0; i < n; ++i) {
    if(dif <= 0) return false;
    
    if(i == 0) {
      if(a[0] == dif) {
        --dif;
      } else if(a[0] > dif) {
        return false;
      }
      continue;
    }
    
    if(a[i] - a[i - 1] == dif) {
      --dif;
    } else if(a[i] - a[i - 1] > dif) {
      return false;
    }
  }
  
  return true;
}

void doomed() {
  int n;
  cin >> n;
  
  vector<int> a(n);
  for(int& x : a) cin >> x;
  
  int l = 0, r = 1000000000, m;
  int maxDif = 0;
  while(l <= r) {
    m = l + (r - l) / 2;
    if(check(m, a)) {
      r = m - 1;
      maxDif = m;
    } else {
      l = m + 1;
    }
  }
  
  cout << maxDif << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  
  for(int i = 1; i <= t; ++i) {
    cout << "Case " << i << ": ";
    doomed();
  }
  
  return 0;
}
