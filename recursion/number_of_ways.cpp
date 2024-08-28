#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

ll ways(ll x, ll y) {
  if (x==y) return 1;
  ll sum=ways(x+1,y);
  if (x+2<=y) sum+=ways(x+2,y);
  if (x+3<=y) sum+=ways(x+3,y);
  return sum;
}

void solve() {
  int x,y;
  cin >> x >> y;
  cout << ways(x,y) << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}

