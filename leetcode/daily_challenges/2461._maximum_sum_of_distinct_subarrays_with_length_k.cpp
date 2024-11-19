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

// Wrong solution
// fails some test cases
class Solution {
  using ll = long long;
public:
  long long maximumSubarraySum(vector<int>& nums, int k) {
    unordered_map<ll, ll> freq{};
    ll l=0,r=-1,n=nums.size(),sum=0;
    for (ll i=0; i<n && (r-l+1)<k; i++) {
      if (i==0 || freq.find(nums[i])==freq.end()) {
        sum+=nums[i];
        freq[nums[i]]++;
        r++;
#ifdef NDEBUG
        cout << format("l: {}, r: {}, i: {}, nums[i]: {}\n", l, r, i, nums[i]);
#endif
      } else {
        for (ll j=l;j<i;j++) {
          freq.erase(nums[j]);
          sum-=nums[i];
          if (nums[j]==nums[i]) {
            l=j+1;
            break;
          }
        }
        sum+=nums[i];
        freq[nums[i]]++;
        r++;
      }
    }
#ifdef NDEBUG
    cout << format("initial: l: {}, r: {}\n", l, r);
#endif
    if (r-l+1==k) {
      ll msum=sum;
      while (r+1<n) {
        sum-=nums[l],freq[nums[l]]--;
        if (freq[nums[l]]==0) freq.erase(nums[l]);
        l++;
        ++r,sum+=nums[r];
        if (freq.find(nums[r])==freq.end()) {
          msum=max(msum,sum);
        }
        freq[nums[r]]++;
#ifdef NDEBUG
        cout << format("l: {}, r: {}, msum: {}, nums[r]: {}\n", l, r, msum, nums[r]);
#endif
      }
      return msum;
    } else return 0;
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

