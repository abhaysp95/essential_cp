#include <bits/stdc++.h>
#include <lc_list.hpp>

using namespace std;

#define uint unsigned int
// #define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

class Solution {
  using ll = long long;
public:
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<set<ll>> adj(n);
    vector<int> res{};
    for (auto &q: queries) {
      adj[q[0]].insert(q[1]);
      ll i=0,l=0;
      while (i<n-1) { // once reaching n-1, it shouldn't iterate
        if (adj[i].empty()) i++;
        else {
          i=*(adj[i].rbegin());
        }
        l++;
#ifdef NDEBUG
        cout << format("l: {}, i: {}\n", l, i);
#endif
      }
      res.push_back(l);
#ifdef NDEBUG
      for (ll i=0; i<n; i++) {
        cout << i << ": ";
        for (auto &x: adj[i]) cout << x << " ";
        cout << "\n";
      }
      cout << "--------\n";
#endif
    }
    return res;
  }
};

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<vector<int>> arr = read_vector_2d<int>(s);
  Solution solve{};
  auto v = solve.shortestDistanceAfterQueries(n, arr);
  for (auto &x: v) cout << x << " ";
  cout << '\n';
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

