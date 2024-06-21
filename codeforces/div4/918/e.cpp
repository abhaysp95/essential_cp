#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
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
    int n = nxt();

    int sum = 0;
    bool stat = false;
    map<int, int> umap{};
    umap[0] = 1;
    for (int i = 0; i < n; i++) {
        int x = nxt();
        if ((i & 1) == 0) {
            sum += x;
        } else sum -= x;
        if (umap[sum]) {
            stat = true;
        } else umap[sum]++;
    }

    cout << (stat ? "YES" : "NO") << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

