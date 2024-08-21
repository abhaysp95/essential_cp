#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("breedflip.in");
ofstream fout("breedflip.out");


void solve() {
  int n;
  fin >> n;
  string a, b;
  fin >> a >> b;

  int count=0;
  for (int i=0; i<n; i++) {
    int j=i;
    if (b[j]!=a[i]) {
      while (i<n&&b[j]!=a[i])
        b[j++]=a[i++];
      count++;
      i--;
    }
  }
  fout << count << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}

