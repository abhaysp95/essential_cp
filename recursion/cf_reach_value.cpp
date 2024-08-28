#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

bool is_possible(ll x, ll n) {
  if (x==n || n==1) return true;
  if (x>n) return false;
  return is_possible(x*10,n) || is_possible(x*20,n);
}

void solve() {
  ll n;
  cin >> n;
  cout << (is_possible(1,n)?"YES":"NO") << '\n';
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

