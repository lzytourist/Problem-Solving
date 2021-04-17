#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int n, q;
vector<int> sacks, tree;

void Set(int i, int v) {
  while(i <= n) {
    tree[i] += v;
    i = i + (i & -i);
  }
}

int Get(int i) {
  int sum = 0;
  
  while(i > 0) {
    sum += tree[i];
    i -= i & (-i);
  }
  
  return sum;
}

void doomed() {
  cin >> n >> q;
  
  sacks = vector<int>(n);
  tree = vector<int>(n + 1, 0);
  
  for(int i = 0; i < n; ++i) {
    cin >> sacks[i];
    Set(i + 1, sacks[i]);
  }
  
  while(q--) {
    int cmd;
    cin >> cmd;
    
    if(cmd == 1) {
      int i;
      cin >> i;
      
      cout << sacks[i] << endl;
      
      Set(i + 1, -sacks[i]);
      sacks[i] = 0;
    } else if(cmd == 2) {
      int i, v;
      cin >> i >> v;
      
      Set(i + 1, v);
      sacks[i] += v;
    } else {
      int i, j;
      cin >> i >> j;
      
      int prev = Get(i);
      int sum = Get(j + 1);
      
      cout << sum - prev << endl;
    }
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  
  int t;
  cin >> t;
  
  for(int i = 1; i <= t; ++i) {
    cout << "Case " << i << ":\n";
    doomed();
  }
  
  return 0;
}
