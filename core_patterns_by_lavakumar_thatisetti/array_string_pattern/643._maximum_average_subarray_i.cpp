#include <bits/stdc++.h>
#include <lc_list.hpp>

using namespace std;

class Solution {
public:
  double findMaxAverage(vector<int> &nums, int k) {
    int n = (int)nums.size();
    double ans = numeric_limits<double>::lowest();
    int sum = 0;
    int i = 0, j = 0;
    while (j < k) {
      sum += nums[j++];
    }
    while (j < n) {
      ans = max(ans, sum / (double)k);
      sum -= nums[i++];
      sum += nums[j++];
    }
    ans = max(ans, sum / (double)k);
    return ans;
  }
};

int main() {
  int T = 0;
  cin >> T;
  Solution solve{};
  while (T--) {
    string input{};
    cin >> input;
    vector<int> arr = read_vector<int>(input);
    int k = 0;
    cin >> k;
    cout << solve.findMaxAverage(arr, k) << '\n';
  }
  cout << endl;
}
