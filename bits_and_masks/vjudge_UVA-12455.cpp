// https://vjudge.net/problem/UVA-12455

#include <cstdio>

using namespace std;

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n,p;
    scanf("%d %d", &n, &p);
    int bars[p];
    for (int i=0; i<p; i++)
      scanf("%d", &bars[i]);

    if (n==0) {
      printf("YES\n");
      return 0;
    }

    for (int mask=0; mask<=(1<<p); mask++) {
      int j=0;
      int sum=0;
      while (1<<j<mask) {
        if (mask&(1<<j)) sum+=bars[j];
        j++;
      }
      if (sum==n) {
        printf("YES\n");
        return 0;
      }
    }
  }

  printf("NO\n");

  return 0;
}
