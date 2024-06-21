#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
        int ld = 0, rd = 0;
        int n =  (int)nums.size();

        for (int i = 1; i < n; i++) {
            if (nums[i - 1] >= nums[i]) {
                ld = i - 1;
                break;
            }
        }

        for (int i = n - 1; i >= 1; i--) {
            if (nums[i - 1] >= nums[i]) {
                rd = i;
                break;
            }
        }

        long long count = 0;

        /* for (int l = 0; l < n; l++) {
            for (int r = l; r < n; r++) {
                if (r <
            }
        } */

        return 0;
    }
};

int main(void) {
    int n = 0;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    Solution sol{};
    sol.incremovableSubarrayCount(nums);
}
