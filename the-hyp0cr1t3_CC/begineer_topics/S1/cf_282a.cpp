// https://codeforces.com/problemset/problem/282/A

#include <iostream>
#include <string>
using namespace std;

int main(void) {
  int x;
  std::cin >> x;

  string s;
  int num = 0;
  while (x--) {
    cin >> s;
    if (s[0] == '+' || s[2] == '+') {
      num += 1;
    } else if (s[0] == '-' || s[2] == '-') {
      num -= 1;
    }
  }

  cout << num << endl;

  return 0;
}
