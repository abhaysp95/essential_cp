#include <functional>
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
    ll n = nxt(), x = nxt();
    vector<int> narr(n), xarr(x);

    for (ll i = 0; i < n; i++) narr[i] = nxt();
    for (ll i = 0; i < x; i++) xarr[i] = nxt();

    sort(all(narr), greater<>());
    sort(all(xarr));
    /* for (ll i = 0; i < n; i++) cout << narr[i] << " ";
    cout << '\n';
    for (ll i = 0; i < x; i++) cout << xarr[i] << " ";
    cout << '\n'; */

    ll i = 0, j = n - 1, l = 0, r = x - 1;

    ll sum = 0;
    while (i <= j) {
        ll d1 = abs(narr[i] - xarr[l]), d2 = abs(narr[j] - xarr[r]);
        if (d1 < d2) {
            sum += d2;
            j--, r--;
        } else if (d1 > d2) {
            sum += d1;
            i++, l++;
        } else {
            sum += d1;
            if (narr[i] > xarr[i]) {
                j--, r--;
            } else i++, l++;
        }
    }

    cout << sum << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

