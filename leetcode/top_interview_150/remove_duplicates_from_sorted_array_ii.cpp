#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <cmath>
#include <string>
#include <sstream>
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
        int removeDuplicates(vector<int>& nums) {
            ll u = 0, i = 0, c = 0;
            while (i < sz(nums)) {
                if (i != 0 && nums[i] != nums[i - 1]) {
                    c = 0;
                    nums[u++] = nums[i];
                } else if (c <= 1) {
                    nums[u++] = nums[i];
                }
                i++, c++;
            }

            for (ll i = 0; i < sz(nums); i++) cout << nums[i] << " ";
            cout << '\n';

            return u;
        }
};

void solve() {
    string input;
    cin >> input;
    input = input.substr(1, sz(input) - 2);

    stringstream istream(input);
    string token;
    vector<int> nums;
    while (getline(istream, token, ',')) {
        if (!token.empty()) nums.push_back(stoi(token));
    }

    Solution solve;
    cout << solve.removeDuplicates(nums) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

