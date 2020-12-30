#include <bits/stdc++.h>

#define F first
#define S second

using namespace std;

int main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	
	int t;
	scanf("%d", &t);
	
	map<int, char> mp;
	int sum = 0;
	for(int i = 0, p = 1; i < 26; ++i) {
		mp[p] = char('a' + i);
		sum += p;
		p <<= 1;
	}

	while(t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		
		if(k < n || k > sum) puts("-1");
		else if(k == n) {
			for(int i = 0; i < n; ++i) {
				printf("a");
			}
			puts("");
		}
		else {
			bitset<32> bits(k);
			
			priority_queue<int> Q;
			for(int i = 31; i >= 0; --i) {
				if(bits[i] == 1) {
					Q.push(1 << i);
				}
			}
			
			while((int)Q.size() < n) {
				int p = Q.top();
				Q.pop();
				
				Q.push(p / 2);
				Q.push(p / 2);
			}
			
			if((int)Q.size() == n) {
				while(!Q.empty()) {
					printf("%c", mp[Q.top()]);
					Q.pop();
				}
				puts("");
			} else {
				puts("-1");
			}
		}
	}
	
	return 0;
}

