// https://codeforces.com/problemset/problem/1097/B

#include <iostream>
#include <vector>
using namespace std;

bool is_lock_opened(int i, int s, vector<int>& arr, int n) {
  // base case
  if (i >= n) {
    if (s % 360 == 0)
      return true;
    return false;
  }

  return is_lock_opened(i + 1, s + arr[i], arr, n) || is_lock_opened(i + 1, s - arr[i], arr, n);
}

int main(void) {
  int n = 0;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << (is_lock_opened(0, 0, arr, n) ? "yes" : "no") << '\n';

  return 0;
}
