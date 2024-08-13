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

#define SZ (int)1e5+1
vector<int> pre(SZ, 0);
void precompute_phi_function() {
  pre[1]=1;
  for (int i=2; i<SZ; i++)
    pre[i]=i-1;

  for (int i=2; i<=SZ; i++) {
    if (pre[i]==i-1) {
      for (int j=2*i; j<=SZ; j+=i)
        pre[j]-=pre[j]/i;
    }
  }
}

// same as above
void precompute_phi_function2() {
  pre[1]=1;
  for (int i=2; i<SZ; i++)
    pre[i]=i;

  for (int i=2; i<=SZ; i++) {
    if (pre[i]==i) {
      for (int j=i; j<=SZ; j+=i)
        pre[j]-=pre[j]/i;
    }
  }
}

int main(void) {
  int t=0;
  scanf("%d", &t);
  precompute_phi_function2();
  while (t--) {
    int n;
    scanf("%d", &n);
    printf("%d\n", pre[n]);
  }
  return 0;
}
