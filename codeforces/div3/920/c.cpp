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

#define sz(a) (ll)(a.size())
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

/* void solve() {
    ll n, cl, cm, toggle;
    cin >> n >> cl >> cm >> toggle;
    vector<ll> tstamp(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        cin >> tstamp[i];
    }

    ll i = 0;
    for (i = 1; i <= n; i++) {
        if (cl <= 0) break;
        ll diff = tstamp[i] - tstamp[i - 1];
        if (diff > toggle) {
            cl -= toggle;
        } else {
            if (diff * cm > cl) {
                cout << "NO" << '\n';
                return;
            }
            cl -= (diff * cm);
        }
    }

    cout << "cl: " << cl << '\n';

    cout << "YES" << '\n';
} */

void solve () {
    ll n, cl, cm, toggle;
    cin >> n >> cl >> cm >> toggle;
    vector<ll> tstamp(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        cin >> tstamp[i];
    }

    for (ll i = 1; i <= n; i++) {
        ll d = tstamp[i] - tstamp[i - 1];
        ll reduced = min(toggle, d * cm);
        cl -= reduced;

        if (cl <= 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
}

int32_t main(void) {
	FAST_IO;

	ll T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

