#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

#define endl '\n'
#define F first
#define S second
#define pb push_back

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

const int N = 2000001;
vector<pair<int, int>> nums(N);

void gen() {
    vector<int> spf(N);
    
    for (int i = 1; i < N; ++i) {
        spf[i] = i;
        
        if (i % 2 == 0) {
            spf[i] = 2;
        }
    }
    
    for (ll i = 3; i * i <= 1LL * N; i += 2) {
        if (spf[i] == i) {
            for (ll j = i * i; j < 1LL * N; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }
        
    nums[1] = {1, 0};
    
    for (int i = 2; i < N; ++i) {
        int cnt = 0;
        int x = i;
        
        while (x != 1) {
            x /= spf[x];
            ++cnt;
        }
        
        nums[i] = {i, cnt};
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    gen();
    sort(nums.begin() + 1, nums.end(), [&](pair<int, int> const &a, pair<int, int> const &b) -> bool {
        if (a.S == b.S) {
            return a.F < b.F;
        }
        
        return a.S < b.S;
    });
    
    int n, tc = 1;
    while(cin >> n) {
        if (n == 0) {
            break;
        }
        
        cout << "Case " << tc++ << ": " << nums[n].F << endl;
    }
    
    return 0;
}
