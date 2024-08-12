
#include <cstdio>
#include <vector>
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

// Time-complexity: O(sqrt(n)) because each division reduces n significantly and
// so the division is limit, we don't need to consider it
// If we add the test-cases the time-complexity is O(t*sqrt(n))
int by_prime_factorization(int n) {
  int c=1; 
  for (int i=2; i*i<=n; i++) {
    int tc=0;
    while (n%i==0) {
      n/=i;
      tc++;
    }
    if (tc) c*=tc+1;
  }

  // NOTE: here if we have i=n>1, then number i is also a divisor and so will be
  // n/i (divisor pair). Thus we need to multiply by 2
  // This is very same to how we needed to check for n>1 in distinct prime
  // factors and added +1 when n>1 was true
  if (n>1) c*=2;

  return c;
}

#define SZ (int)1e6+1
vector<int> pdivides(SZ,0);
void precompute_prime_divisors() {
  pdivides[1] = 1;
  for (int i = 2; i<=SZ; i++) {
    int k=i;
    if (pdivides[k]==0) {
      while (k<=SZ) {
        pdivides[k]=i;
        k+=i;
      }
    }
  }
}

// Time-complexity: Doing precomputation will take O(nlog(n))
// and then for computing divisors for n will only take O(log(n))
// so, total complexity will be: O(nlog(n))+O(tlog(n))
// This is better when number are more on larger side
int optimized_prime_factorization(int n) {
  int c=1;
  int d=pdivides[n];
  while (n>1) {
    int tc=0;
    while (n%d==0) {
      n/=d;
      tc++;
    }
    if (tc) c*=tc+1;
    d=pdivides[n];
  }
  return c;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    int c = by_prime_factorization(n);
    printf("%d\n",c);
  }
}
