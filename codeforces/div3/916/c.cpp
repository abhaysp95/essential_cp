#include <climits>
#include <iostream>
#include <fstream>
#include <numeric>
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

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

void solve() {
    int n = nxt(), k = nxt();
    vector<int> av(n, 0);
    vector<int> bv(n, 0);

    for (int i = 0; i < n; i++) av[i] = nxt();
    for (int i = 0; i < n; i++) bv[i] = nxt();

    int msum = -1;
    int asum = 0;
    int maxb = -1;
    for (int i = 0; i < k && i < n; i++) {
        asum += av[i];
        maxb = max(maxb, bv[i]);
        msum = max(msum, asum + maxb * (k - i - 1));
    }

    cout << msum << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

