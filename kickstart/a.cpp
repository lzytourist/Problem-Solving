#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void doomed() {
  int n;
  string s;
  
  cin >> n >> s;
  
  for(int i = 0; i < n; ++i) {
    int j = i - 1;
    int cnt = 1;
    while(j >= 0 && s[j] < s[j + 1]) {
      ++cnt;
      --j;
    }
    
    cout << cnt;
    if(i < n - 1) cout << " ";
    else cout << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  
  for(int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    doomed();
  }
  
  return 0;
}
