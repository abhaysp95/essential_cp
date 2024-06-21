#include <bits/stdc++.h>

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

// works only for odd
/* void solve() {
    int n = nxt();

    if (!(n & 1)) { // even
        cout << -1 << '\n';
        return;
    }

    int mn = n * n;
    int odd = 1, even = 0;

    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0 || j == 0) {
                mat[i][j] = odd;
                odd += 2;
            } else {
                if (even + 2 > mn) {
                    mat[i][j] = odd;
                    odd += 2;
                } else {
                    even += 2;
                    mat[i][j] = even;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j];
            if (j + 1 < n) cout << ' ';
        }
        cout << '\n';
    }
} */

void solve() {
    int n = nxt();
    if (n == 1) {
        cout << 1 << '\n';
        return;
    } else if (n == 2) {
        cout << -1 << '\n';
        return;
    }

    vector<vector<int>> mat(n, vector<int>(n, 0));

    int sq = n * n;
    int odd = 0, even = sq / 2;
    if (!(sq & 1)) {  // even
        odd = sq / 2;
    } else odd = (sq + 1) / 2;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i && odd) {
                mat[j][i] = 1;  // fill row first order
                odd--;
            }
            if (!odd) break;
        }
        if (!odd) break;
    }

    // check in the last sq. matrix the number of 1s should be odd
    int count = n;
    for (int i = 1; i < n; i++) {
        if (mat[i][n - 1] == 1) {
            count++;
        } else break;
    }

    if (!(count & 1)) {
        mat[n - 2][n - 2] = 0;
        mat[n - 2][0] = 1;  // doing this, will make one more odd element countable for last sq. block
    }

    odd = 1, even = 2;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j]) {
                mat[i][j] = odd;
                odd += 2;
            } else {
                mat[i][j] = even;
                even += 2;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mat[i][j];
            if (j + 1 < n) cout << ' ';
        }
        cout << '\n';
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

