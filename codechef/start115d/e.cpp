// GREEDLIS

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
    int n = nxt(), x = nxt();
    vector<int> arr(n);
    // iota(all(arr), 1);

    if (n == x || n - x < 2) {
        cout << -1 << '\n';
        return;
    }
    if (x == 0) {
        for (int x: arr) {
            cout << x << " ";
        }
        cout << '\n';
        return;
    }

    int r = x + 1;
    for (int i = n - r, k = 1; i < n; i++, k++) {
        arr[i] = k;
    }

    for (int i = 0, k = n; i < n - r; i++, k--) {
        arr[i] = k;
    }

    for (int x: arr) {
        cout << x << " ";
    }
    cout << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

