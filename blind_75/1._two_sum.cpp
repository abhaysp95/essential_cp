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
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<vector<ll>> nmap(nums.size(), vector<ll>(2));
    for (ll i=0; i<nums.size(); i++) nmap[i][0]=i, nmap[i][1]=nums[i];
    sort(nmap.begin(), nmap.end(), [](auto &f, auto &l) {
      return f[1] < l[1];
    });
    ll i=0, j=nums.size()-1;
    while (i<j) {
      if (nmap[i][1]+nmap[j][1]==target) {
        return vector<int>{(int)nmap[i][0], (int)nmap[j][0]};
      } else if (nmap[i][1]+nmap[j][1]<target) {
        i++;
      } else j--;
    }
    return vector<int>{};
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

