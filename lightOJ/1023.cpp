#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void doomed() {
	int n, k;
  scanf("%d%d", &n, &k);
  
  string s = "";
  for(int i = 0; i < n; ++i) {
    s += char('A' + i);
  }
  
  do {
    printf("%s\n", s.c_str());
    --k;
  } while(k > 0 && next_permutation(s.begin(), s.end()));
}

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	// cout.tie(nullptr);
	
	int t;
	scanf("%d", &t);
	// cin >> t;
	
	for(int i = 1; i <= t; ++i) {
		printf("Case %d:\n", i);
		// cout << "Case " << i << ": ";
		doomed();
	}
	
	return 0;
}
