#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

// vector<vector<ll>> space(2e5+1,vector<ll>(2e5+1,-1));
//
// ll defeated(int i, int di, vector<int>& m) {
//   if (i==m.size()) {
//     return 0;
//   }
//   if (space[i][di]!=-1) return space[i][di];
//   // take i
//   ll score=0;
//   if (di%2) {
//     score=2*m[i]+defeated(i+1,di+1,m);
//   } else {
//     score=m[i]+defeated(i+1,di+1,m);
//   }
//   // not take and return
//   return space[i][di] = max(score,defeated(i+1,di,m));
// }

// solution works but will take too much space where n is large
void solve() {
  int n;
  cin >> n;
  vector<int> m(n,0);
  for (int i=0;i<n;i++) cin >> m[i];
  // cout << defeated(0,0,m) << '\n';

  vector<vector<ll>> space(n+1,vector<ll>(n+1,0));
  for (int i=1;i<=n;i++) {
    for (int di=1;di<=i;di++) {
      ll score=0;
      if (di&1) score=m[i-1]+space[i-1][di-1];
      else score=2*m[i-1]+space[i-1][di-1];
      space[i][di]=max(score,space[i-1][di]);
    }
  }
  // for (int i=0;i<=n;i++) {
  //   for (int j=0;j<=n;j++)
  //     cout << space[i][j] << " ";
  //   cout << '\n';
  // }
  ll mp=space[n][0];
  for_each(space[n].begin(),space[n].end(),[&mp](auto &p) { mp=max(mp,p); });
  cout << mp << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}

