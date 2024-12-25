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

void bubble_sort(vector<int>& arr) {
  for (ll i=0; i<arr.size()-1; i++) {
    for (ll j=i+1; j<arr.size(); j++) {
      if (arr[i]>arr[j]) swap(arr[i], arr[j]);
    }
  }
}

void solve() {
  vector<int> arr = {20, 12, 10, 15, 2};
  bubble_sort(arr);
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

