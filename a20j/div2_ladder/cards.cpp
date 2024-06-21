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

    ll cz = 0, cn = 0;
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == 'z') cz++;
        else if (c == 'n') cn++;
    }

    /* if (cn == 0) {
        cout << 0 << '\n';
        return;
    } */

    while (cn--) {
        cout << 1 << " ";
    }
    while (cz--) {
        cout << 0 << " ";
    }
    cout << '\n';

/*
    ll num = 0;

    for (int i = 0; i < cn; i++) {
        num += 1;
        if (i != cn - 1) num *= 10;
    }
    for (int i = 0; i < cz; i++) {
        num *= 10;
    }

    cout << num << '\n'; */
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

