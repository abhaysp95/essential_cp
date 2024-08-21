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
  ll n,k;
  cin >> n >> k;
  vector<ll> days(n);
  for (ll i=0; i<n; i++)
    cin >> days[i];

  ll i=0;
  ll tot=0;
  while (i<n) {
    ll j=i;
    while (j+1<n && days[j+1]-days[j]+1+k<(k+1)*2) j++;
    if (j-i!=0) {
      tot+=(days[j]-days[i]+1+k);
      i=j;
    } else {
      tot+=(k+1);
    }
    i++;
  }

  cout << tot << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}

