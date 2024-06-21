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

vector<pair<int, int>> pos(1e6 + 1);

void solve() {
    int n = nxt(), q = nxt();

    pos[0] = {1, 0};
    int cur = 1;
    int t = 0;
    for (int i = 0; i < q; i++) {
        int type = nxt();
        if (type == 1) {
            char m = 0;
            cin >> m;
            if (m == 'U') {
                pos[cur] = {pos[cur - 1].first, pos[cur - 1].second + 1};
            } else if (m == 'D') {
                pos[cur] = {pos[cur - 1].first, pos[cur - 1].second - 1};
            } else if (m == 'L') {
                pos[cur] = {pos[cur - 1].first - 1, pos[cur - 1].second};
            } else if (m == 'R') {
                pos[cur] = {pos[cur - 1].first + 1, pos[cur - 1].second};
            }
            cur++;
            t++;
        } else {
            int p = nxt();
            if (p - 1 >= t) {
                cout << p - t << " " << 0 << '\n';
            } else {
                int pidx = t - (p - 1);
                pair<int, int> pre = pos[pidx];
                cout << pre.first << " " << pre.second << '\n';
            }
        }
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

