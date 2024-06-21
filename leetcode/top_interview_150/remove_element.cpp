#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <cmath>
#include <string>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define INF (int)1e9

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

inline ll nxt(istream& cin = std::cin) {
	ll x;
	cin >> x;
	return x;
}

class Solution {
    public:
        // not so efficient way
        int removeElement_first(vector<int>& nums, int val) {
            vector<int> ans{};
            sort(all(nums));

            for (ll i = 0; i < sz(nums); i++) {
                if (nums[i] != val) ans.push_back(nums[i]);
            }

            nums = ans;  // std::move not necessary

            return sz(nums);
        }

        int removeElement_second(vector<int>& nums, int val) {
            sort(all(nums));

            ll fidx = distance(nums.begin(), lower_bound(all(nums), val));
            ll sidx = distance(nums.begin(), upper_bound(all(nums), val));

            ll idx = fidx;
            for (ll j = sidx; j < sz(nums); idx++, j++) {
                nums[idx] = nums[j];
            }

            nums.resize(idx);

            /* for (ll i = 0; i < sz(nums); i++) cout << nums[i] << ' ';
            cout << '\n'; */

            return idx;
        }
};

void solve() {
    string input;
    cin >> input;
    ll val = nxt();
    input = input.substr(1, sz(input) - 2);

    stringstream istream(input);
    string token;
    vector<int> nums;

    while (getline(istream, token, ',')) {
        if (!token.empty()) nums.push_back(stoi(token));
    }

    Solution solve;
    cout << solve.removeElement_second(nums, val) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

