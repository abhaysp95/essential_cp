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
#include <cstring>
#include <iterator>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define INF (int)1e9

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
    vector<ll> seq(n);
    vector<bool> avail(10, false);

    for (ll i = 0; i < n; i++) seq[i] = nxt();
    for (ll i = 0; i < x; i++) {
        ll k = nxt();
        avail[k] = true;
    }

    vector<ll> ans{};
    for (ll i = 0; i < n; i++) {
        if (avail[seq[i]]) ans.push_back(seq[i]);
    }

    for (auto x: ans) cout << x << " ";
    cout << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

