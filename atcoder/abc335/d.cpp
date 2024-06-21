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

void solve() {
    int n = nxt();

    vector<vector<string>> vec(n, vector<string>(n));

    int l = 0, t = 0, r = n - 1, b = n - 1;
    int c = 1;
    while (l <= r && t <= b) {
        for (int i = l; i <= r; i++, c++) {
            vec[t][i] = to_string(c);
        }
        t++;
        for (int i = t; i <= b; i++, c++) {
            vec[i][r] = to_string(c);
        }
        r--;
        for (int i = r; i >= l; i--, c++) {
            vec[b][i] = to_string(c);
        }
        b--;
        for (int i = b; i >= t; i--, c++) {
            vec[i][l] = to_string(c);
        }
        l++;
    }

    int m = n / 2;
    vec[m][m] = 'T';

    for (auto v: vec) {
        for (int i = 0; i < n; i++) {
            cout << v[i];
            if (i + 1 < n) cout << ' ';
        }
        cout << '\n';
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

