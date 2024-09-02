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
  vector<int> lh, rh;
  for (int i=0;i<n;i++) {
    int x;
    char h;
    cin >> x >> h;
    if (h=='L') lh.push_back(x);
    else rh.push_back(x);
  }
  int f=0;
  for (int i=1;i<lh.size();i++) {
    f+=abs(lh[i]-lh[i-1]);
  }
  for (int i=1;i<rh.size();i++) {
    f+=abs(rh[i]-rh[i-1]);
  }
  cout << f << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}

