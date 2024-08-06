// https://codeforces.com/problemset/problem/1097/B

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n = 0;
  cin >> n;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  for (int m = 0; m < 1 << n; m++) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
      if (m & (1 << i))
        sum += arr[i];
      else
        sum -= arr[i];
    }

    if (sum % 360 == 0) {
      cout << "yes" << '\n';
      return 0;
    }
  }
  cout << "no" << '\n';

  return 0;
}
