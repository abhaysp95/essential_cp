// https://cses.fi/problemset/task/1623
// Apple Division

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
  int n;
  cin >> n;
  vector<int> w(n);
  for (int i=0;i<n;i++)
    cin >> w[i];

  ll mdiff=1e9+1;
  for (int m=0;m<(1<<n);m++) {
    ll sa=0,sb=0;
    for (int i=0;i<n;i++) {
      if (m&(1<<i)) sa+=w[i];
      else sb+=w[i];
    }
    mdiff=min(mdiff,abs(sa-sb));
  }

  cout << mdiff << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}

