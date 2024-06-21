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
    vector<vector<char>> mat(3, vector<char>(3));

    int qi = 0, qj = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            char c;
            cin >> c;
            if (c == '?') qi = i, qj = j;
            mat[i][j] = c;
        }
    }

    vector<bool> pre(3, false);
    for (int i = 0; i < 3; i++) {
        if (mat[qi][i] != '?') pre[mat[qi][i] - 'A'] = true;
    }

    for (int i = 0; i < 3; i++) {
        if (!pre[i]) {
            cout << (char)(i + 'A') << '\n';
            break;
        }
    }
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

