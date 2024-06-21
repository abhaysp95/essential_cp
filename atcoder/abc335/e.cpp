#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

void solve() {
    int n = nxt(), m = nxt();
    vector<int> score(n);

    generate(all(score), nxt);
    vector<vector<int>> adj(n + 1);
    for (int i= 0; i < m; i++) {
        int x = nxt(), y = nxt();
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    function<void(int, int)> dfs = [&](int node, int par) {
        for (int x: adj[node]) {
            if (x != par) {
                dfs(x, node);
            }
        }
    };
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

