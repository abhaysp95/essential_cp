#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <unordered_map>
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

vector<vector<ll>> space;

int total_sleigh(const vector<int>& sleigh, ll x, int idx, ll csum) {
    if (idx == sleigh.size()) return 0;

    if (space[idx][csum] != -1) return space[idx][csum];

    int l = 0, r = 0;
    l = total_sleigh(sleigh, x, idx + 1, csum);
    if (csum + sleigh[idx] <= x)
        r = 1 + total_sleigh(sleigh, x, idx + 1, csum + sleigh[idx]);

    return space[idx][csum] = max(l, r);
}

void solve() {
    int n = nxt(), q = nxt();
    vector<int> sleigh(n);

    for (int i = 0; i < n; i++) sleigh[i] = nxt();

    space.resize(n + 1, vector<ll>(2 * (int)1e14, -1));
    while (q--) {
        ll x;
        cin >> x;
        ll sum = accumulate(all(sleigh), 0);
        if (sum < x) {
            cout << sleigh.size() << '\n';
            continue;
        }
        cout << total_sleigh(sleigh, x, 0, 0) << '\n';
    }
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

