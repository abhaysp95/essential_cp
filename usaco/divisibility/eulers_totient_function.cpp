#include <cstdio>
#include <vector>
using namespace std;

// gives the count of coprimes for given n, between [1, n]
// phi(n) = n(1-1/p1)(1-1/p2)...(1-1/pk)
// what is coprime and how we reached to above conclusion ?
// read: https://cp-algorithms.com/algebra/phi-function.html

// time-complexity: O(sqrt(n))
void with_prime_factorization_method(int n) {
  int res=n;
  for (int i=2; i*i<=n; i++) {
    if (n%i==0) {
      while (n%i==0) n/=i;
      res-=res/i;
    }
  }
  if (n>1) res-=res/n;
  printf("%d\n", res);
}

int main(void) {
  int t=0;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    with_prime_factorization_method(n);
  }
  return 0;
}
