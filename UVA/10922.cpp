#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	while(cin >> s) {
		if(s == "0") {
			break;
		}
		
		int sum = 0;
		for(int i = 0; i < (int) s.length(); ++i) {
			sum += s[i] - '0';
		}
		
		if(sum % 9 != 0) {
			cout << s << " is not a multiple of 9." << endl;
			continue;
		}
		
		int cnt = 0;
		while(sum % 9 == 0 && sum > 9) {
			++cnt;
			
			int x = sum;
			sum = 0;
			
			while(x > 0) {
				sum += x % 10;
				x /= 10;
			}
		}
		
		if(sum == 9) {
			++cnt;
		}
		
		cout << s << " is a multiple of 9 and has 9-degree " << cnt << "." << endl;
	}
	
	return 0;
}
