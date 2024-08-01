// https://codeforces.com/problemset/problem/110/A


#include <cstdint>
#include <cstdio>
#include <iostream>
using ull = unsigned long long;

using namespace std;

int main(void) {
  uint64_t x = 0;
  cin >> x;
  size_t count = 0;
  while (x) {
    if (int rem = x % 10; rem == 7 || rem == 4) {
      count ++;
    }
    x /= 10;
  }
  cout << (count == 4 || count == 7 ? "YES" : "NO") << endl;

  return 0;
}

// NOTE: be careful with numbers more than 1e9. CF judge didn't work with %zu to
// take for uint64_t
