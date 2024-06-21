#include <functional>
#include <iostream>
#include <fstream>
#include <numeric>
#include <queue>
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

    vector<int> color(k);

    for (int i = 0; i < k; i++) color[i] = nxt();

    vector<int> diff(k - 1);

    for (int i = 0; i < k - 1; i++) {
        diff[i] = color[i + 1] - color[i];
    }

    priority_queue<int> heap; // max heap

    for (int i = 0; i < k - 1; i++) {
        heap.push(diff[i]);
        if (i >= k / 2) heap.pop();
    }

    ll sum = 0;
    while (!heap.empty()) {
        sum += heap.top();
        heap.pop();
    }

    cout << sum << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

