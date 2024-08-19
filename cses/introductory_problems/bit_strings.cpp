// this is the problem of Modular exponantiation

#include <cstdio>

using namespace std;

#define M 1000000007
#define ll long long

ll pow(ll x, ll y) {
  if (!y) {
    return 1;
  }
  if (y&1) {
    return x*pow(x,y-1)%M;
  } else {
    return pow(x*x%M, y/2); 
  }
}

int main(void) {
  ll n;
  scanf("%lld", &n);

  // printf("%lld", pow(2, n));
  ll x=2;
  ll res=1;
  while (n) {
    if (n&1) {
      res=res*x%M;
    } 
    x=x*x%M;
    n/=2;
  }

  printf("%lld", res);

  return 0;
}
