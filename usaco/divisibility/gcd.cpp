#include <cstdio>
#include <numeric>
#include <algorithm>
using namespace std;

// Euclidean algo for gcd:
// if b = 0, gcd(a, b) = a
// if b != 0, gcd(a, b) = gcd(b, a mod b)

int gcd_manual(int a, int b) {
  while (b) {
    int r = a % b;
    a = b;
    b = r;
  }

  return a;
}

int gcd17(int a, int b) {
  return gcd(a, b);
}

int gcd14(int a, int b) {
  return __gcd(a, b);  // import <algorithm>
}

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", gcd_manual(a, b));
  printf("%d\n", gcd17(a, b));
  printf("%d\n", gcd14(a, b));
}
