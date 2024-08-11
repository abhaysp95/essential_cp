
#include <cstdio>
using namespace std;

// recieved TLE (because there are multiple test cases)
int brute_force(int n) {
  int c=2;
  for (int i=2; i<=n/2; i++) {
    if (n%i==0) c++;
  }
  return c;
}

// NOTE: Why this works ?
// Divisor Pairs:
// For i*i<=n, if i divides n, then n/i is also a divisor. Thus, for each i, we
// add count of 2 to divisor's count
// Except, when i*i==n, because then i & n/i will be the same number
int divisor_pairs(int n) {
  int c=0;
  for (int i=1; i*i<=n; i++) {
    if (n%i==0) c += i*i==n?1:2;
  }
  return c;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int c = divisor_pairs(n);
    printf("%d\n",c);
  }
}
