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

/* void solve() {
    ll n = nxt();
    vector<ll> arr(n);

    for (ll i = 0; i < n; i++) arr[i] = nxt();

    ll c = 0;
    for (ll i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1]) c++;
    }

    if (c != 0) c--;

    cout << c << '\n';
} */

void solve() {
    ll n = nxt();
    ll t1 = INF, t2 = INF;

    ll count = 0;
    while (n--) {
        if (t1 > t2) swap(t1, t2);  // t1 will always be the smaller one

        ll x = nxt();
        if (x <= t1) t1 = x;
        else if (x <= t2) t2 = x;
        else {  // bigger than both t1 & t2
            t1 = x;
            count++;
        }
    }

    cout << count << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

