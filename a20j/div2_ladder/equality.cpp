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
#include <functional>
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
    ll n = nxt(), k = nxt();
    string s;
    cin >> s;

    vector<ll> vec(26, 0);
    ll maxl = 0;

    function<void(ll)> good = [&](ll idx) {
        bool stat = true;
        for (ll i = 1; i < k; i++) {
            if (vec[i] != vec[i - 1]) {
                stat = false;
                break;
            }
        }

        if (stat) {
            maxl = max(maxl, vec[0] * k);
        }
        if (idx == n) return;

        vec[s[idx] - 'A']++;
        good(idx + 1);
        vec[s[idx] - 'A']--;
        good(idx + 1);
    };

    good(0);

    cout << maxl << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

