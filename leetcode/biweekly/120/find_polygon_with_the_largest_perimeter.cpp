#include <vector>

using namespace std;

class Solution {
    public:
        long long largestPerimeter(vector<int>& nums) {
            sort(nums.begin(), nums.end());

            int n = (int)nums.size();
            long long sum = nums[0] + nums[1];
            long long maxp = -1;

            for (int i = 2; i < n; i++) {
                if (nums[i] < sum) maxp = max(maxp, sum + nums[i]);
                sum += nums[i];
            }

            return maxp;
        }
};
