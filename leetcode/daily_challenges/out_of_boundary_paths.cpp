#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <cmath>
#include <string>
#include <sstream>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>

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
            // space.resize(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
            space.resize(m, vector<vector<int>>());
            for (ll i = 0; i < m; i++) space[i].resize(n, vector<int>(maxMove + 1, -1));

            function<int(int, int, int, int, int)> max_paths = [&](int x, int y, int k, int i, int j) -> int {
                if (i < 0 || i == m || j < 0 || j == n) return 1;
                if (!k) return 0;

                if (space[i][j][k] != -1) return space[i][j][k];  // didn't even cross this line

                int drow[4] = {-1, 0, 0, 1};
                int dcol[4] = {0, -1, 1, 0};
                int sum = 0;
                for (ll p = 0; p < 4; p++) {
                    int ni = drow[p] + i;
                    int nj = dcol[p] + j;
                    sum = (sum + max_paths(x, y, k - 1, ni, nj)) % MOD;
                }

                space[i][j][k] = sum;
                return sum;
            };

            int res = max_paths(m, n, maxMove, startRow, startColumn);

            /* for (ll i = 0; i < m; i++) {
                {
                    int c = maxMove;
                    for (int j = 0; j < n; j++) {
                        for (int k = 0; k < c; k++) {
                            cout << space[i][j][k] << " ";
                        }
                        cout << '\n';
                    }
                    cout << "\n-------------\n";
                }
            } */

            return res;
        }
};

void solve() {
    ll m = nxt(), n = nxt(), k = nxt(), i = nxt(), j = nxt();

    Solution solve;
    cout << solve.findPaths(m, n, k, i, j) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

