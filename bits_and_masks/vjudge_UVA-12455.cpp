// https://vjudge.net/problem/UVA-12455

#include <cstdio>

using namespace std;

void solve() {
  int n,p;
  scanf("%d %d", &n, &p);
  int bars[p];
  for (int i=0; i<p; i++)
    scanf("%d", &bars[i]);

  bool stat=false;

  for (int mask=0; mask<(1<<p); mask++) {
    int j=0;
    int sum=0;
    while (j<p) {
      if (mask&(1<<j)) sum+=bars[j];
      j++;
    }
    if (sum==n) {
      stat=true;
      break;
    }
  }

  printf("%s\n", stat||n==0?"YES":"NO");
}

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    solve();
  }

  return 0;
}
