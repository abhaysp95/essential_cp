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
    int xd = 0, yd = 0;
    vector<vector<int>> axis(4, vector<int>(2, 0));
    for (int i = 0; i < 4; i++) {
        cin >> axis[i][0] >> axis[i][1];
    }

    sort(all(axis), [](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) return a[1] < b[1];
            return a[0] < b[0];
            });

/*
    for (int i = 0; i < 4; i++) {
        cout << axis[i][0] << " " << axis[i][1] << '\n';
    } */

    xd = abs(axis[0][0] - axis[3][0]);
    yd = abs(axis[1][1] - axis[2][1]);

    cout << xd * yd << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

