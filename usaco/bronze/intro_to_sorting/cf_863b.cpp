// https://codeforces.com/contest/863/problem/B

#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");


/** NOTES:
 * Pay attention to constraint, n was at max 50, so the solution can be a brute
 * force one
 */


void solve() {
  ll n;
  cin >> n;
  vector<ll> w(2*n);
  for (ll i=0; i<2*n; i++) cin >> w[i];
  sort(w.begin(), w.end());
  // for (auto &x: w) cout << x << ' ';
  // cout << '\n';

  ll md=1e9;
  for (ll i=0; i<2*n; i++) {
    for (ll j=i+1; j<2*n; j++) {
      ll res=0;
      for (ll k=0; k<2*n; k+=2) {
        // cout << format("i, j, k: {}, {}, {}\n", i, j, k);
        ll d=0;
        if (k==i) k++;
        if (k==j) k++;
        if (k+1==j && k+2<2*n) {
          d=abs(w[k]-w[k+2]);
        } else {
          if (k+1<2*n) d=abs(w[k]-w[k+1]);
        }
        res+=d;
        // cout << format("d, res: {}, {}\n", d, res);
      }
      md=min(md,res);
      // dbg(md);
    }
  }
  cout << md << '\n';
}

void solve_wrong() {
  ll n;
  cin >> n;
  vector<ll> w(2*n);
  for (ll i=0; i<2*n; i++) cin >> w[i];
  sort(w.begin(), w.end());

  ll res=0,md=-1e9;
  for (ll i=0; i<2*n; i+=2) {
    ll d=abs(w[i]-w[i+1]);
    md=max(md, d);
    res+=d;
  }
  res-=md;
  ll res2=0;
  for (ll i=1; i<2*n-1; i+=2) {
    res2+=abs(w[i]-w[i+1]);
  }
  cout << min(res,res2) << '\n';
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

