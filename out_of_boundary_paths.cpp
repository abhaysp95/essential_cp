#include <bits/stdc++.h>

using namespace std;

#define INF (int)1e9
#define MOD (INF + 7)

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

inline ll nxt(istream& cin = std::cin) {
	ll x;
	cin >> x;
	return x;
}

class Solution {
	vector<vector<vector<int>>> space;

	public:
		int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
			space.resize(m, vector<vector<int>>());
			for (ll i = 0; i < m; i++) space[i].resize(n, vector<int>(maxMove + 1, -1));

			function<int(int, int, int, int, int)> max_paths = [&](int x, int y, int k, int i, int j) {
				if (i < 0 || i == m || j < 0 || j == n) return 1;
				if (!k) return 0;

				if (space[i][j][k] != -1) return space[i][j][k];

				int sum = 0;
				int drow[4] = {-1, 0, 0, 1};
				int dcol[4] = {0, -1, 1, 0};
				for (ll p = 0; p < 4; p++) {
					int ni = drow[p] + i;
					int nj = dcol[p] + j;
					sum  = (sum + max_paths(x, y, k - 1, ni, nj)) % MOD;
				}

				return space[i][j][k] = sum;
			};

			return max_paths(m, n, maxMove, startRow, startColumn);
		}
};

void solve() {
	int n = nxt(), m = nxt(), k = nxt(), i = nxt(), j = nxt();

	Solution solve;
	cout << solve.findPaths(n, m, k, i, j) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

