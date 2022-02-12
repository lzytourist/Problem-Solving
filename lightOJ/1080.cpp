#include <bits/stdc++.h>

#define endl '\n'
#define F first
#define S second
#define mp make_pair
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

class Segment {
	vector<int> tree, lazy;
	int N;
	
	void build(int node, int l, int r, string const &s) {
		if (l == r) {
			if (l < (int) s.length()) {
				tree[node] = s[l] - '0';
			}
			return;
		}
		
		int m = l + (r - l) / 2;
		int ln = (node << 1) + 1;
		int rn = (node << 1) + 2;
		
		build(ln, l, m, s);
		build(rn, m + 1, r, s);
		
		tree[node] = tree[ln] + tree[rn];
	}
	
	void update(int node, int l, int r, int &i, int &j) {
		int ln = (node << 1) + 1;
		int rn = (node << 1) + 2;
		
		if (lazy[node] != 0) {
			tree[node] += (r - l + 1) * lazy[node];
			
			if (l != r) {
				lazy[ln] += lazy[node];
				lazy[rn] += lazy[node];
			}
			
			lazy[node] = 0;
		}
		
		if (l > j || r < i) {
			return;
		}
		
		if (l >= i && r <= j) {
			tree[node] += (r - l + 1);
			
			if (l != r) {
				lazy[ln] += 1;
				lazy[rn] += 1;
			}
			
			return;
		}
		
		int m = l + (r - l) / 2;
		update(ln, l, m, i, j);
		update(rn, m + 1, r, i, j);
		
		tree[node] = tree[ln] + tree[rn];
	}
	
	int get(int node, int l, int r, int &k) {
		int ln = (node << 1) + 1;
		int rn = (node << 1) + 2;
		
		if (lazy[node] != 0) {
			tree[node] += (r - l + 1) * lazy[node];
			
			if (l != r) {
				lazy[ln] += lazy[node];
				lazy[rn] += lazy[node];
			}
			
			lazy[node] = 0;
		}
		
		if (l == k && r == k) {
			return tree[node];
		}
		
		if (l > k || r < k) {
			return 0;
		}
		
		int m = l + (r - l) / 2;
		
		int r1 = get(ln, l, m, k);
		int r2 = get(rn, m + 1, r, k);
		
		return r1 + r2;
	}
	
public:
	Segment(string const &s) {
		int n = s.length();
		N = 1;
		while(N < n) {
			N <<= 1;
		}
		tree.assign(2 * N, 0);
		lazy.assign(2 * N, 0);
		
		build(0, 0, N - 1, s);
	}
	
	void update(int i, int j) {
		update(0, 0, N - 1, i, j);
	}
	
	int get(int k) {
		return get(0, 0, N - 1, k) & 1;
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	
	for(int tc = 1; tc <= t; ++tc) {
		cout << "Case " << tc << ":" << endl;
		
		string s;
		cin >> s;
		
		Segment seg(s);
		
		int q;
		cin >> q;
		
		while(q--) {
			char c;
			cin >> c;
			
			if(c == 'I') {
				int i, j;
				cin >> i >> j;
				--i, --j;
				
				seg.update(i, j);
			} else {
				int k;
				cin >> k;
				--k;
				
				cout << seg.get(k) << endl;
			}
		}
	}
	
	return 0;
}
