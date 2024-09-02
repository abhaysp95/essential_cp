#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");


void solve() {
  int a,b;
  cin >> a >> b;
  int res=0;
  if (a==b) {
    res=1;
  } else if (abs(a-b)%2==0) {
    res=3;
  } else res=2;
  cout << res << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}
