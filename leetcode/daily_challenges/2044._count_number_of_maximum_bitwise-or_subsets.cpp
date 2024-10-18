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

class Solution {
  using ll = long long;

public:
  int countMaxOrSubsets(vector<int>& nums) {
    ll n = nums.size();
    ll mn = 0, mbwor=0;
    // doesn't make a difference in this problem, whether you start with i=0
    for (ll i=1; i<(1<<n); i++) {
      ll bwor=0;
      for (ll j=0; j<n; j++) {
        if ((i & (1<<j)) != 0) {
          // cout << nums[j] << " ";
          bwor |= nums[j];
        }
      }
      if (bwor > mbwor) {
        mn = 1;
        mbwor = bwor;
      } else if (bwor == mbwor) mn++;
      // cout << '\n';
    }
    return mn;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> nums(n, 0);
  for (int i=0; i<n; i++) cin >> nums[i];
  Solution solve;
  cout << solve.countMaxOrSubsets(nums) << '\n';
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

