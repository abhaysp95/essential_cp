#include <bits/stdc++.h>
#include <lc_list.hpp>

using namespace std;

class Solution {
  int bin_search(vector<int>& arr, int l, int r, int f, int t) {
    while (l <= r) {
      int m = l + (r - l) / 2;
      if (int sum = arr[m] + arr[f]; sum == t) {
        return m;
      } else if (sum > t) {
        r = m - 1;
      } else l = m + 1;
    }
    return -1;
  }
public:
  // binary search approach
  vector<int> twoSum(vector<int>& numbers, int target) {
    int n = (int)numbers.size();
    for (int i=0; i<n; i++) {
      if (int idx = bin_search(numbers, i+1, n-1, i, target); idx != -1) {
        return vector<int>{i + 1, idx + 1};
      }
    }
    return vector<int>{};
  }
};

int main() {
  Solution solve{};

  int T=0;
  cin >> T;
  while (T--) {
    string input{};
    cin >> input;
    vector<int> arr = read_vector<int>(input);
    int t=0;
    cin >> t;
    vector<int> ans = solve.twoSum(arr, t);
    cout << "{" << ans[0] << ", " << ans[1] << "}\n";
  }
  cout << endl;
}
