#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
// #define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

// brute force solution
class Solution {
  using ll = long long;
  #define INF 1e9+7;
public:
  int maxWidthRamp(vector<int>& nums) {
    ll maxw=0;
    for (ll i=0; i<nums.size(); i++) {
      for (ll j=i+1; j<nums.size(); j++) {
        if (nums[i]<=nums[j]) {
          maxw=max(maxw,j-i);
        }
      }
    }
    return maxw;
  }
};

void solve() {
	// type here
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

