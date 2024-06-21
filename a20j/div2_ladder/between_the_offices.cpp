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

void solve() {
    int n = nxt();
    string trip;
    cin >> trip;

    int l = 0, r = 0;
    int sf = 0, fs = 0;  // ques: is sf greater ?
    while (r < n) {
        if (trip[l] != trip[r]) {
            if (trip[l] == 'S') sf++;
            else fs++;
            l = r;
        }
        r++;
    }
    /* if (trip[l] != trip[r]) {
        if (trip[l] == 's') sf++;
        else fs++;
    } */

    cout << (sf > fs ? "YES" : "NO") << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}
