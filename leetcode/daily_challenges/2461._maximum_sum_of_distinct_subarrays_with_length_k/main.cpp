#include <bits/stdc++.h>
#include "../lc_list.hpp"

using namespace std;

#define uint unsigned int
//#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

class Solution {
  using ll = long long;
public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    if (k==1) {
      return *max_element(nums.begin(), nums.end());
    }
    unordered_map<ll, ll> freq{};
    ll l=0,r=0,n=nums.size();
    ll sum=0,msum=0;
    while (r<n) {
      freq[nums[r]]++;
      sum += nums[r];
      if (r-l+1>k) {  // slide the window
        freq[nums[l]]--;
        if (freq[nums[l]]==0) freq.erase(nums[l]);
        sum-=nums[l];
        l++;
      }
      while (freq[nums[r]]!=1) {  // check validity
        freq[nums[l]]--;
        if (freq[nums[l]]==0) freq.erase(nums[l]);
        sum-=nums[l];
        l++;
      }
      if (r-l+1==k) {
        msum=max(msum,sum);
      }
      r++;
    }
    return msum;
  }
};

void solve() {
  string s;
  cin >> s;
  auto arr = read_vector<int>(s);
  for (auto &x: arr) cout << x << ' ';
  cout << '\n';
  int k;
  cin >> k;
  Solution solve{};
  cout << solve.maximumSubarraySum(arr, k) << endl;
}

int32_t main(void) {
  FAST_IO;

	int T;
  cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}

