#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
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


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

int traverse(vector<vector<int>>& adj, int node, vector<int>& d, vector<int>& l, vector<int>& r, int c) {
    d[node] = c;  // put depth

    int ans = 0;
    for (int x: adj[node]) {
        ans = traverse(adj, x, d, l, r, c + 1);
    }

    if (adj[node].empty()) {
        l[node] = 1;
        r[node] = 0;
    } else {
        for (int x: adj[node]) {
            r[node] = min(r[node], r[x]);
            l[node] += l[x];
        }
        r[node]++;
    }

    if (r[node] <= d[node]) {
        // cout << node << ", " << l[node] << ", " << r[node] << ", " << d[node] << '\n';
        return max(ans, l[node]);
    }

    return ans;
}

void solve() {
    int n = nxt();

    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int x = nxt(), y = nxt();
        adj[x].push_back(y);
    }

    // depth, leaf nodes count, min. time to reach u node from one of it's leaf
    vector<int> d(n + 1, 0), l(n + 1, 0), r(n + 1, 0);
    cout << traverse(adj, 1, d, l, r, 0);
    cout << '\n';
}

void solve2() {
    int n = nxt();
    vector<vector<int>> adj(n + 1);
    for (int i = 1; i < n; i++) {
        int x = nxt(), y = nxt();
        adj[x].push_back(y);

        // NOTE: somehow not using this gives error in some test cases, how ?
        adj[y].push_back(x);
    }

    vector<int> d(n + 1, 0), l(n + 1, 0), r(n + 1, 1e9 + 7);

    function<void(int, int)> dfs = [&](int node, int parent) {
        bool is_leaf = true;
        for (int x: adj[node]) {
            if (x == parent) {
                // cout << x << " " << parent << '\n';
                continue;
            }
            is_leaf = false;
            d[x] = d[node] + 1;
            dfs(x, node);  // call again
            l[node] += l[x];
            r[node] = min(r[node], r[x] + 1);
        }

        if (is_leaf) {
            l[node] = 1;
            r[node] = 0;
        }
    };

    dfs(1, 0);

    int ans = 0;
    for (int i = 1; i < n + 1; i++) {
        // cout << i << ", " << l[i] << ", " << r[i] << ", " << d[i] << '\n';
        if (r[i] != 0 && r[i] <= d[i]) {
            ans = max(ans, l[i]);
        }
    }

    cout << ans << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve2();
	}

	return 0;
}

