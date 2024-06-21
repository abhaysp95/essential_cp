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
#include <cstring>
#include <iterator>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define INF (int)1e9

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

int space[1001][8];
/*
4
5 C
6 B
16 BAC
4 A */

/* 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 1000000000 0

1000000000 1000000000 1000000000 5 1000000000 1000000000 1000000000 0

1000000000 11 1000000000 5 1000000000 6 1000000000 0

16 11 16 5 16 6 16 0

15 11 9 5 10 6 4 0

15 */

void tabulated_push_earlier() {
    int n = nxt();
    vector<int> cost(n);
    vector<int> vits(n);

    for (int i = 0; i < n; i++) {
        cost[i] = nxt();
        string s;
        cin >> s;
        int mask = 0;
        for (int i = 0; i < sz(s); i++) {
            mask |= 1 << (s[i] - 'A');
        }
        vits[i] = mask;
    }

    memset(space, 0, sizeof(space));
    /* fill_n(space[n], 8, 1e9);
    space[n][7] = 0;

    int x = 0, px = 0;

    for (ll i = n - 1; i >= 0; i--) {
        for (ll j = 0; j <= 7; j++) {
            space[i][j] = min(space[i + 1][j], cost[i] + space[i + 1][j | vits[i]]);
        }
    } */

    fill_n(space[0], 8, 1e9);
    space[0][7] = 0;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 0; j <= 7; j++) {
            space[i][j] = min(space[i - 1][j], cost[i - 1] + space[i - 1][j | vits[i - 1]]);
        }
    }

    /* for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            cout << space[i][j] << " ";
        }
        cout << '\n';
    } */

    // cout << space[0][0] << '\n';
    cout << (space[n][0] >= INF ? -1 : space[n][0])  << '\n';
}

void tabulated_push() {
    int n = nxt();
    vector<int> cost(n);
    vector<int> vits(n);

    for (int i = 0; i < n; i++) {
        cost[i] = nxt();
        string s;
        cin >> s;
        int mask = 0;
        for (int i = 0; i < sz(s); i++) {
            mask |= 1 << (s[i] - 'A');
        }
        vits[i] = mask;
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            space[i][j] = INF;
        }
    }
    space[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 8; j++) {
            space[i + 1][j] = min(space[i + 1][j], space[i][j]);
            space[i + 1][j | vits[i]] = min(space[i + 1][j | vits[i]], cost[i] + space[i][j]);
        }
    }

    /* for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 8; j++) {
            cout << space[i][j] << " ";
        }
        cout << '\n';
    } */

    // cout << space[0][0] << '\n';
    cout << (space[n][7] >= INF ? -1 : space[n][7])  << '\n';
}

int min_cost(const vector<int>& cost, const vector<int>& vits, int idx, int vf) {
    if (vf == 7 ) return 0;
    if (idx == sz(cost)) return 1e9;

    if (space[idx][vf] != -1) return space[idx][vf];

    return space[idx][vf] = min(min_cost(cost, vits, idx + 1, vf),
            cost[idx] + min_cost(cost, vits, idx + 1, vf | vits[idx]));
}

void solve() {
    /* int n = nxt();
    vector<int> cost(n);
    vector<int> vits(n);

    for (int i = 0; i < n; i++) {
        cost[i] = nxt();
        string s;
        cin >> s;
        int mask = 0;
        for (int i = 0; i < sz(s); i++) {
            mask |= 1 << (s[i] - 'A');
        }
        vits[i] = mask;
    }

    memset(space, -1, sizeof(space));

    ll res = min_cost(cost, vits, 0, 0);
    cout << (res < 1e9 ? res : -1)  << '\n'; */

    /* for (int i = 0; i < n; i++) {
        // recurrance relation
        space[i + 1] = space[i][x];
        x |= (curr);
        space[i + 1] = min(space[i + 1], space[i][x]);
    } */

    tabulated_push();
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

