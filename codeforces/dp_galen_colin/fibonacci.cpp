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

int space[51];  // this is just poc, not actual soln.

// limit to n = 50
int memoized_fib(int n) {
    if (n <= 1) return n;
    if (space[n] != -1) return space[n];

    return space[n] = memoized_fib(n - 1) + memoized_fib(n - 2);
}

int tabulation_pull_dp(int n) {
    memset(space, -1, sizeof(space));
    space[0] = 0, space[1] = 1;

    for (int i = 2; i <= n; i++) {
        space[i] = space[i - 1] + space[i - 2];
    }

    return space[n];
}

int tabulation_push_dp(int n) {
    memset(space, -1, sizeof(space));
    space[0] = 0, space[1] = 1;

    for (int i = 1; i < n; i++) {
        space[i + 1] += space[i];
        space[i + 2] += space[i];
    }

    return space[n];
}

void solve() {
    memset(space, -1, sizeof(space));
	// type here
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

