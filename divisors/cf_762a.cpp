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
  priority_queue<ll> maxheap;
  maxheap.push(1);
  if (n!=1) {
    maxheap.push(n);
    if (maxheap.size()>k) maxheap.pop();
  }
  for (ll i=2;i*i<=n;i++) {
    if (n%i==0) {
      maxheap.push(i);
      if (maxheap.size()>k) maxheap.pop();
      if (i!=n/i) {
        maxheap.push(n/i);
        if (maxheap.size()>k) maxheap.pop();
      }
    }
  }
  if (maxheap.size()!=k) cout << -1 << '\n';
  else cout << maxheap.top() << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}

// NOTE: Edgecases
// 1. if n is 1, then there will be only 1 divisor, either one or n, not both
// 2. insert in heap one time, when i==n/i
