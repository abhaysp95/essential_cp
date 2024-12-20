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
  using ll=long long;
  unordered_map<string, int> umap{};
public:
  // memoized solution works but gives TLE
  ll max_length(vector<int>& nums, ll idx, ll prev) {
    if (idx==nums.size()) {
      return 0;
    }
    string key = to_string(idx) + "_" + to_string(prev);
    if (umap.find(key)!=umap.end()) return umap[key];
    ll maxl=0;
    if (prev==-1e5||prev<nums[idx]) {
      maxl=max(1+max_length(nums, idx+1, nums[idx]), max_length(nums, idx+1, prev));
    }
    return umap[key]=max(maxl, max_length(nums, idx+1, prev));
  }
  int lengthOfLIS(vector<int>& nums) {
    // -1e5 for prev, because -1e4 <= nums[i] <= 1e4
    return max_length(nums, 0, -1e5);
  }
};

void solve() {
	// type here
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

// bruteforce will not work: [0,1,0,3,2,3]
int lengthOfLIS_bruteforce(vector<int>& nums) {
  ll mlength=0;
  for (ll i=0; i<nums.size(); i++) {
    ll j=i+1, prev=nums[i];
    ll c=1;
    for (; j<nums.size()-1; j++) {
      if (prev<nums[j]) prev=nums[j], c++;
      cout << format("i, j, prev, c: {}, {}, {}, {}\n", i, j, prev, c);
    }
    mlength=max(mlength, c);
  }
  return mlength;
}

