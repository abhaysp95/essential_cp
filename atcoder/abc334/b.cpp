#include <iostream>
#include <fstream>

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

inline long long nxt(istream& cin = std::cin) {
	long long x;
	cin >> x;
	return x;
}

void solve() {
    long long a = nxt(), m = nxt(), l = nxt(), r = nxt();


    if (l == r) {
        cout << 0 << '\n';
        return;
    }

    ll count = 0;
    for (ll k = 0; ; k++) {
        ll val = a + k * m;
        if (val > r) break;
        else if (val >= l && val <= r) {
            count++;
        }
    }

    for (ll k = -1; ; k--) {
        ll val = a + k * m;
        if (val < l) break;
        else if (val >= l && val <= r) {
            count++;
        }
    }

    cout << count << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

