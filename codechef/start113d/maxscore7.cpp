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

// failed
/* void solve() {
    int n = nxt();
    vector<int> arr(n);

    for (int i = 0; i < n; i++) arr[i] = nxt();

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == -1) continue;
        if ((arr[i] == 0 && arr[i + 1] == 1)
                || (arr[i] == 1 && arr[i + 1] == 0)) {
            sum++;
            arr[i] = -1, arr[i + 1] = -1;
        }
    }

    cout << sum << '\n';
} */

void solve() {
    int n = nxt();

    int cone = 0, czero = 0;
    for (int i = 0; i < n; i++) {
        int x = nxt();
        x == 0 ? czero ++ : cone++;
    }

    cout << min(czero, cone) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

