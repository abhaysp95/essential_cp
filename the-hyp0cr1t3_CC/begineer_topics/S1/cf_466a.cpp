// https://codeforces.com/problemset/problem/466/A

#include <iostream>

using namespace std;

int main(void) {
  int n = 0, m = 0, a = 0, b = 0;
  cin >> n >> m >> a >> b;

  int m_trips = n / m;
  int sum = min(m_trips * b, m_trips * m * a);
  if (int left = (n % m) * a; left <= b) {
    sum += left;
  } else sum += b;

  cout << sum << endl;

  return 0;
}
