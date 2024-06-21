#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <cmath>
#include <string>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

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

inline ll nxt(istream& cin = std::cin) {
	ll x;
	cin >> x;
	return x;
}

void solve() {
    ll n, k;
    cin >> n >> k;

    ll lec[n], awake[n];
    memset(lec, 0, sizeof(lec));
    memset(awake, 0, sizeof(awake));
    for (int i = 0; i < n; i++) cin >> lec[i];
    for (int i = 0; i < n; i++) cin >> awake[i];

    ll pall[n], pawake[n];
    memset(pall, 0, sizeof(pall));
    memset(pawake, 0, sizeof(pawake));
    pall[0] = lec[0];
    pawake[0] = awake[0] ? lec[0] : 0;
    for (int i = 1; i < n; i++) {
        pall[i] = pall[i - 1] + lec[i];
        pawake[i] = pawake[i - 1] + (awake[i] ? lec[i] : 0);
    }

#ifdef DEBUG
    for (int i = 0; i < n; i++) {
        cout << pall[i] << " | " << pawake[i] << '\n';
    }
#endif

    ll ans = -1, sum = -1;
    for (int i = 0; i < n - k + 1; i++) {
        sum = pall[i + k - 1];
#ifdef DEBUG
        cout << "1: " << sum << " | ";
#endif
        if (i != 0) {
            sum -= pall[i - 1];
#ifdef DEBUG
            cout << "2: " << sum << " | ";
#endif
            sum += pawake[i - 1];
#ifdef DEBUG
            cout << "3: " << sum << " | ";
#endif
        }
        if (n - 1 > i + k - 1) {
            sum += (pawake[n - 1] - pawake[i + k - 1]);
#ifdef DEBUG
            cout << "4: " << sum << " | ";
#endif
        }
#ifdef DEBUG
        cout << "sum: " << sum << '\n';
#endif
        ans = max(ans, sum);
    }

    cout << (ans == -1 ? pall[n - 1] : ans) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

