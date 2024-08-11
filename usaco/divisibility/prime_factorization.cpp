#include <cstdio>
#include <vector>

using namespace std;

vector<int> factors(int n) {
  vector<int> res;
  for (int i=2; i*i<=n; i++) {
    if (n%i==0) {
      res.push_back(i);
      while (n%i==0)
        n/=i;
    }
  }
  if (n>1) res.push_back(n);
  return res;
}

int main() {
  int n;
  scanf("%d", &n);
  auto res = factors(n);
  for (int &x: res) {
    printf("%d ", x);
  }
  printf("\n");
}
