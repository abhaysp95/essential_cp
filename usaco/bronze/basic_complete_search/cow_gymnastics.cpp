#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("gymnastics.in");
ofstream fout("gymnastics.out");


void solve() {
  ll k,n;
  fin >> k >> n;
  vector<vector<ll>> grid(k, vector<ll>(n));
  for (ll i=0; i<k; i++) {
    for (ll j=0; j<n; j++) fin >> grid[i][j];
  }

  ll c=0;
  for (ll i=1; i<=n; i++) {
    for (ll j=1; j<=n; j++) {
      if (i!=j) {
        bool g=true;
        for (ll s=0; s<k; s++) {
          ll pi=0,pj=0;
          // find i
          for (; pi<n; pi++) if (grid[s][pi]==i) break;
          // find j
          for (; pj<n; pj++) if (grid[s][pj]==j) break;
          if (pi>pj) {
            g=false;
            break;
          }
        }
        if (g) {
#ifdef NDEBUG
          cout << format("i: {}, j: {}\n", i, j);
#endif
          c++;
        } 
      }
    }
  }
  fout << c << '\n';
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

