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
    ll t = nxt();
    while (t--) {
        ll maxd = -1;
        ll n = nxt();
        string s;
        cin >> s;

        ll r = 0, l = -1;
        while (r < n) {
            if (s[r] == 'A') {
                if (l == -1) l = r;
                else {
                    maxd = max(maxd, r - l - 1);
                    l = r;
                }
            }
            r++;
        }

        if (l == -1) {
            cout << 0 << '\n';
            continue;
        }

        if (s[n - 1] == 'P') maxd = max(maxd, n - l - 1);
        cout << (maxd == -1 ? 0 : maxd) << '\n';
    }
}

int32_t main(void) {
    FAST_IO;

    int T = 1;
    while (T--) {
        solve();
    }

    return 0;
}

