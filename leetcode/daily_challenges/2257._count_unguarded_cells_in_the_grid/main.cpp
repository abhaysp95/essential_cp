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

// NOTE: don't confuse this with backtracking problem
class Solution {
  using ll = long long;
public:
  int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
    vector<vector<bool>> visited(m, vector<bool>(n, false));
    vector<vector<bool>> grid(m, vector<bool>(n, false));
    for (ll i=0; i<guards.size(); i++) {
      ll r=guards[i][0],c=guards[i][1];
      grid[r][c]=true;
      visited[r][c]=true;
    }
    for (ll i=0; i<walls.size(); i++) {
      ll r=walls[i][0],c=walls[i][1];
      grid[r][c]=true;
      visited[r][c]=true;
    }
    for (ll i=0; i<guards.size(); i++) {
      // traverse left
      ll r=guards[i][0], c=guards[i][1];
      while (--c>=0) {
        if (grid[r][c]) break;
        else visited[r][c]=true;
      }
      // traverse right
      r=guards[i][0], c=guards[i][1];
      while (++c<n) {
        if (grid[r][c]) break;
        else visited[r][c]=true;
      }
      // traverse up
      r=guards[i][0], c=guards[i][1];
      while (--r>=0) {
        if (grid[r][c]) break;
        else visited[r][c]=true;
      }
      // traverse down
      r=guards[i][0], c=guards[i][1];
      while (++r<m) {
        if (grid[r][c]) break;
        else visited[r][c]=true;
      }
    }
    ll free=0;
    for (ll i=0; i<m; i++)
      for (ll j=0; j<n; j++) 
        if (!visited[i][j]) free++;
#ifdef NDEBUG
    for (auto &x: grid) {
      for (auto c: x) cout << c << " ";
      cout << '\n';
    }
    cout << "--------\n";
#endif
#ifdef NDEBUG
    for (auto &x: visited) {
      for (auto c: x) cout << c << " ";
      cout << '\n';
    }
#endif
    return free;
  }
};

void solve() {
  int m,n;
  cin >> m >> n;
  string in1, in2;
  cin >> in1 >> in2;
  auto guards = read_vector_2d<int>(in1);
  auto walls = read_vector_2d<int>(in2);
  Solution s;
  cout << s.countUnguarded(m, n, guards, walls) << '\n';
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

