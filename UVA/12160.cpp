#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define PI acos(-1.0)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using pii = pair<int, int>;

const int INF = 1e9 + 7;

#ifdef halcyon
#define dbg(x) cout << "Line: " << __LINE__ << " says: " << #x << " = " << x << "\n"
#else
#define dbg(x)
#endif

void doomed(int l, int U, int R) {
  vector<int> btns(R);
  for(int& x : btns) cin >> x;
  
  queue<int> Q;
  vector<int> lvl(10000, -1);
  
  Q.push(l);
  lvl[l] = 0;
  
  while(!Q.empty()) {
    int u = Q.front();
    Q.pop();
    
    for(int btn : btns) {
      int c = btn + u;
      int exac = 0;
      
      for(int i = 0, r, p = 1; i < 4; ++i, p *= 10) {
        r = c % 10;
        c /= 10;
        
        exac = (r * p) + exac;
      }
      
      if(lvl[exac] == -1) {
        lvl[exac] = lvl[u] + 1;
        Q.push(exac);
      }
    }
  }
  
  if(lvl[U] == -1) {
    cout << "Permanently Locked" << endl;
  } else {
    cout << lvl[U] << endl;
  }
}

int main()
{
  // ios_base::sync_with_stdio(false);
  // cin.tie(nullptr);
  
  int t = 1;
  int l, u, r;
  
  while(cin >> l >> u >> r) {
    if(l == 0 && u == 0 && r == 0) break;
    
    cout << "Case " << t++ << ": ";
    doomed(l, u, r);
  }
}
