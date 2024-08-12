#include <cstdio>
#include <numeric>
using namespace std;

int lcm(int a, int b) {
  int hcf = gcd(a, b);
  return (a/hcf)*b;  // will prevent integer overflow from a*b
}
// NOTE: for multiple numbers get the gcd for each one, ie., get the gcd for
// first two then replace those 2 with gcd and get it's gcd with next neighbour
// and so on
// and then take lcm by dividing a/hcf and then multiplying by rest of the numbers

int main(void) {
  int a, b;
  scanf("%d %d", &a, &b);
  printf("%d\n", gcd(a, b));
}
