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

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

void solve() {
    int n = nxt();
    vector<int> arr(n);

    for (int i = 0; i < n; i++) arr[i] = nxt();

    sort(all(arr));

    int ans = -1, sz = (int)arr.size();
    int num = arr[sz - 1];

    for (int i = sz - 1; i >= 1; i--) {
        if (arr[i - 1] != arr[i]) {
            ans = arr[i - 1];
            break;
        }
    }

    cout << ans << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

