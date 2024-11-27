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

// NOTE: BFS is used here to find the shortest path on unweighted graph 
class Solution {
  using ll = long long;
public:
  ll min_distance(vector<vector<ll>>& adj) {
    queue<pair<ll, ll>> q{};
    // adj graph can be cyclical
    vector<bool> visited(adj.size(), false);
    q.push({0, 0});
    visited[0]=true;
    ll minl = 1e9;
    while (!q.empty()) {
      auto [cp, cl] = q.front();
      q.pop();
      if (cp==adj.size()-1) {
        minl = min(minl, cl);
      }
      for (auto &x: adj[cp]) {
        if (!visited[x]) {
          q.push({x, cl+1});
          visited[x]=true;
        }
      }
    }
    return minl;
  }
  vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
    vector<vector<ll>> adj(n);
    for (ll i=0; i<n-1; i++) {
      adj[i].push_back(i+1);
    }
    vector<int> res{};
    for (auto &q: queries) {
      adj[q[0]].push_back(q[1]);
#ifdef NDEBUG
      for (ll i=0; i<n; i++) {
        cout << i << ": ";
        for (ll j=0; j<adj[i].size(); j++) cout << adj[i][j] << " ";
        cout << '\n';
      }
      cout << "\n--------\n";
#endif
      ll l = min_distance(adj);
#ifdef NDEBUG
      cout << l << '\n';
#endif
      res.push_back(l);
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
  cout << "\n=============\n";
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

