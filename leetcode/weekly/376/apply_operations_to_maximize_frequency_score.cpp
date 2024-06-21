#include <algorithm>
#include <vector>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl

class Solution {
    public:
        int maxFrequencyScore(vector<int>& nums, long long k) {
            sort(all(nums));

            int n = (int)nums.size();
            int median = n & 1 ? nums[n / 2] : (nums[n / 2] + nums[(n + 1) / 2]) / 2;

            function<int(int, int)> target_sum = [&](int idx, int k) {
                if (k == 0) return 0;
                if (idx == n) return -1;

                int ans = 0;
                bool found = false;
                if (int diff = abs(median - nums[idx]); diff <= k) {
                    int res = target_sum(idx + 1, k - diff);
                    if (res != -1) {
                        found = true;
                        ans = 1 + res;
                    }
                }
                int res = target_sum(idx + 1, k);
                if (res != -1) {
                    found = true;
                    ans = max(ans, res + 1);
                }

                return !found ? -1 : ans;
            };

            return target_sum(0, k);
        }
};
