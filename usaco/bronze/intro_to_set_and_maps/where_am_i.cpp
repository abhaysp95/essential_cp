#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("whereami.in");
ofstream fout("whereami.out");


// brute force
void solve() {
  ll k;
  fin >> k;
  string s;
  fin >> s;

  ll r=1;
  while (r<k) {
    bool valid=true;
    for (ll i=0; i+r-1<s.size(); i++) {
      if (s.find(s.substr(i, r), i+1)!=string::npos) {
        valid=false;
        break;
      }
    }
    if (valid) {
      fout << r << '\n';
      return;
    }
    r++;
  }
}

int32_t main(void) {
  FAST_IO;

	// int T;
 //  cin >> T;
	// while (T--) {
		solve();
	// }

	return 0;
}

