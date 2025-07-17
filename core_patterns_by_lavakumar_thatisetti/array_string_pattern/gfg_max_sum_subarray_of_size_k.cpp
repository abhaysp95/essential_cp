#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  // NOTE:
  // Since the size of subarray is fix (k), prefix sum is able to
  // provide solution at TC of O(n), even though there are two
  // variables i and j, albeit taking extra space
  // If the question would've been of variable size subarray (target sum)
  // using prefix sum would give O(n^2) or O(nlogn), if 0 <= arr[i]
  int maximumSumSubarrayPrefixSum(vector<int> &arr, int k) {
    int n = (int)arr.size();
    vector<int> parr(n + 1);
    for (int i = 0; i < n; i++) {
      parr[i + 1] = parr[i] + arr[i];
    }
    int i = k, j = 0;
    int res = 0;
    while (i <= n) {
      res = max(res, parr[i++] - parr[j++]);
    }
    return res;
  }

  // NOTE:
  // Always check constraints
  // In sliding window problem (fixed size) check:
  // arr[i] is just positive or negative too
  // check whether k in the input can be provided more than n or not
  // always update the final result again after the while loop

  int maximumSumSubarraySlidingWindow(vector<int> &arr, int k) {
    int n = (int)arr.size();
    int l = 0, r = 0;
    int sum = 0, res = 0;
    while (r <= k) {
      sum += arr[r++];
    }
    while (r < n) {
      res = max(res, sum);
      sum -= arr[l++];
      sum += arr[r++];
    }
    res = max(res, sum);
    return res;
  }
};
