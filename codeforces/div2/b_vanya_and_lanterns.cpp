#include <algorithm>
#include <iostream>
#include <fstream>
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


ifstream fin("");
ofstream fout("");

inline int nxt(/*istream& cin = std::cin*/) {
	int x;
	cin >> x;
	return x;
}

void solve() {
    int n = nxt(), l = nxt();

    vector<int> a(n);
    generate(all(a), nxt);

    sort(all(a));

    if (a[a.size() - 1] != l) a.insert(a.end(), l);

    vector<int> diff(n);
    double mdiff = a[0] == 0 ?  a[1] / 2.0 : a[0];

    for (int i = 1; i < n + 1; i++) {
        diff[i - 1] = a[i] - a[i - 1];
        mdiff = max(mdiff, diff[i - 1] / 2.0);
    }

    cout << mdiff << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

