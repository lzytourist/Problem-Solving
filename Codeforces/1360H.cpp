#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

#ifdef lzytourist
#define debug(x) cerr << #x << ": " << x << endl;
#else
#define debug(x)
#endif

typedef unsigned long long int ll;

using namespace std;

ll mid, l, r;
pair<bool, bool> median(int m, vector<ll>& a) {
  ll total = 1ULL << m;
  ll n = a.size();
  
  ll deadLeft = 0, deadRight = 0;
  bool isDead = false;
  for(ll i = 0; i < n; ++i) {
    if(a[i] < mid) {
      ++deadLeft;
    } else if(a[i] > mid) {
      ++deadRight;
    } else {
      isDead = true;
    }
  }
  
  ll aliveOnLeft = mid - deadLeft;
  ll aliveOnRight = total - 1 - mid - deadRight;
  
  if(isDead) {
    if(aliveOnLeft >= aliveOnRight) {
      return {false, true};
    }
    return {false, false};
  }
  
  if(!((total - n) & 1)) {
    if(aliveOnLeft + 1 == aliveOnRight) {
      return {true, false};
    }
  }
  
  if(aliveOnLeft == aliveOnRight) {
    return {true, false};
  } else if(aliveOnLeft > aliveOnRight) {
    return {false, true};
  }
  
  return {false, false};
}

void doomed() {
  ll n, m;
  cin >> n >> m;
  
  vector<ll> a(n);
  for(ll i = 0; i < n; ++i) {
    string s;
    cin >> s;
    
    bitset<64> bin(s);
    a[i] = bin.to_ullong();
  }
  sort(a.begin(), a.end());
  
  l = 0, r = 1ULL << m;
  while(l <= r) {
    mid = l + (r - l) / 2;
    
    pair<bool, bool> med = median(m, a);
    
    if(med.F) {
      bitset<64> bin(mid);
      for(int i = m - 1; i >= 0; --i) {
        cout << bin[i];
      }
      cout << endl;
      break;
    } else if(med.S) {
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  
  int t;
  cin >> t;
  
  for(int i = 1; i <= t; ++i) {
    // cout << "Case " << i << ": ";
    doomed();
  }
  
  return 0;
}
