#include <cmath>
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

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

void solve() {
    int n = nxt();

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        ll num;
        cin >> num;
        sum += num;
    }

    double r = sqrt(sum);
    ll rl = (ll)r;
    if ((r * 10) / 10 == rl) {
        cout << "YES";
    } else cout << "NO";
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

