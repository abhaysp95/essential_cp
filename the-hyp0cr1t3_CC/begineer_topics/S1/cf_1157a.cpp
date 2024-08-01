// https://codeforces.com/contest/1157/problem/A

#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int num = 0;
  cin >> num;

  size_t count = 0;
  if (num % 10 == 0) {
    num += 1;
    count += 1;
  }

  bool one_done = false;
  vector<bool> range1to9(9, false);
  while (true) {
    if (num == 1 and one_done) break;
    if (num == 1) one_done = true;
    if (int res = num % 10; res != 0) {
      if (num >= 1 && num <= 9) {
        if (!range1to9[num]) {
          range1to9[num] = true;
          count += 1;
        }
      } else count += 1;
      num += 1;
    } else {  // res == 0
      while (num % 10 == 0) {
        num /= 10;
      }
    }
  }

  cout << count << endl;

  return 0;
}
