#include <bits/stdc++.h>
#include <lc_list.hpp>

using namespace std;

class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int i = 0, j = 0, n = (int)nums.size();
    while (j < n) {
      if (nums[i] != nums[j]) i++, nums[i] = nums[j];
      j++;
    }
    return i + 1;
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  while (T--) {
    string s{};
    cin >> s;
    vector<int> arr = read_vector<int>(s);
    Solution solve{};
    int k = solve.removeDuplicates(arr);
    for (int i=0; i<k; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  return 0;
}
