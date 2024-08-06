// Consider this problem: You are given N≤20 numbers, each up to 10^9. Is there
// a subset with sum equal to given goal S?

#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int n = 0;
  cin >> n;

  vector<int> vec(n, 0);
  for (int i = 0; i < n; i++)
    cin >> vec[i];

  int target = 0;
  cin >> target;


  // in m, if bit is set, it'll mean to include the number from that index
  for (int m = 0; m < (1 << n); m++) {
    long long sub_sum = 0;
    vector<int> res;
    for (int i = 0; i < n; i++) {
      if (m & (1 << i)) {
        sub_sum += vec[i];
        res.push_back(vec[i]);
      }
    }

    if (sub_sum == target) {
      for (int i = 0; i < res.size(); i++)
        cout << res[i] << ' ';
      cout << '\n';
    }
  }

  return 0;
}

// NOTE: normally this question would be solved with recursion but one can use
// this type of technique. For a number N < 30, this type of bit related
// technique would work because 10^9 < 2^30 (somewhat close, but 2^30 would
// exceed it)
