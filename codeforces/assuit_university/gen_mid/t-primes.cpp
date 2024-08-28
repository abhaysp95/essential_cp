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
  ll n;
  cin >> n;
  int c=0;
  bool broke=false;
  for (int i=2;i*i<=n;i++) {
    if (n%i==0) {
      int t=0;
      while (n%i==0) {
        n/=i;
        t++;
      }
      c+=t+1;
      if (c>3) {
        broke=true;
        break;
      }
    }
  }
  if (n>1&&!broke) c+=2;  // in case n is prime
  cout << (c==3?"YES":"NO") << '\n';
}

int32_t main(void) {
  FAST_IO;

	int T;
  cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}

