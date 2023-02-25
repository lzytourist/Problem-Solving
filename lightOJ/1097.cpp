#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

template<typename T>
void scan(vector<T> &v) {for (T &x : v) cin >> x;};

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

const int N = 1429431;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef LZYTOURIST
    freopen("/home/joker/Documents/code/in", "r", stdin);
    freopen("/home/joker/Documents/code/out", "w", stdout);
#endif

    ordered_set st;
    for (int i = 1; i <= N; i += 2) {
        st.insert(i);
    }

    for (int i = 2; i <= (int) st.size(); ++i) {
        int k = *st.find_by_order(i - 1);
        
        int l = (int) st.size();
        l = (l / k) * k;
        for (int j = l; j >= k; j -= k) {
            st.erase(st.find_by_order(j - 1));
        }
    }

    int t;
    cin >> t;

    for (int tc = 1; tc <= t; ++tc) {
        cout << "Case " << tc << ": ";

        int n;
        cin >> n;

        cout << *st.find_by_order(n - 1) << endl;
    }

    return 0;
}