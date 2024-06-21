#include <cstring>
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

int space[61];

int push_dp(int n) {
    if (n & 1 || n == 0) {
        return 0;
    }

    memset(space, 0, sizeof(space));  // already filled with base condition

    space[0] = 1, space[1] = 1;
    for (int i = 0; i < n - 1; i++) {
        space[i + 2] = 2 * space[i];
    }

    return space[n];
}

int mathematically(int n) {
    if (n & 1) {
        return 0;
    }

    return ((int)pow(2, n / 2));
}

void solve() {
    int n = nxt();

    cout << push_dp(n) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

