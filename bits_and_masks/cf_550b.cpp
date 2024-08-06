// https://codeforces.com/problemset/problem/550/B

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int n, l, r, x;
  cin >> n >> l >> r >> x;

  vector<int> arr(n, 0);
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  int count = 0;
  for (int m = 0; m < (1 << n); m++) {
    int tdiff = 0;
    int ld = 1e9, rd = -1e9;
    int pc = 0;
    for (int i = 0; i < n; i++) {
      if (m & (1 << i)) {
        tdiff += arr[i];
        ld = min(ld, arr[i]);
        rd = max(rd, arr[i]);
        pc++;
      }
    }

    if (pc >= 2 && l <= tdiff && r >= tdiff && rd - ld >= x) {
      count++;
    }

  }

  cout << count << '\n';

  return 0;
}
