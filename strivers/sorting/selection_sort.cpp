#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

void selection_sort(vector<int>& arr) {
  ll start=0, n=arr.size();
  while (start < n) {
    ll midx=start;
    for (ll j=midx; j<n-1; j++) {
      if (arr[j]>arr[j+1]) {
        midx=j+1;
      }
    }
    swap(arr[start], arr[midx]);
    start++;
  }
}

void solve() {
  vector<int> arr = {20, 12, 10, 15, 2};
  selection_sort(arr);
  for (auto& x: arr) cout << x << " ";
  cout << '\n';
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

