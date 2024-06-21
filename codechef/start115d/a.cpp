// APLUSB

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
    int n = nxt();
    vector<int> sarr(n);
    generate(all(sarr), nxt);
    sort(all(sarr));

    vector<int> rsarr(n);
    generate(all(rsarr), nxt);
    sort(all(rsarr), greater<int>());

    int fsum = rsarr[0] + sarr[0];
    for (int i = 1; i < n; i++) {
        if (rsarr[i] + sarr[i] != fsum) {
            cout << -1 << '\n';
            return;
        }
    }

    for (int x: sarr) {
        cout << x << " ";
    }
    cout << '\n';
    for (int x: rsarr) {
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

