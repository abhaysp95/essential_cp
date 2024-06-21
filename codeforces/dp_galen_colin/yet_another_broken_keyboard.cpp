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

void solve() {
    int n = nxt(), x = nxt();
    string str;
    cin >> str;
    unordered_set<char> s;
    for (int i = 0; i < x; i++) {
        char c;
        cin >> c;
        s.insert(c);
    }

    int l = 0, r = 0;
    ll total = 0;
    while (r < n) {
        if (!s.count(str[r])) {
            if (l != r) {
                ll len = r - l;
                total += (len * (len + 1)) / 2;
                l = r;
            }
            l++;
        }
        r++;
    }

    if (l != r) {
        ll len = r - l;
        total += (len * (len + 1)) / 2;
    }

    cout << total << '\n';
}

int space[(int)(2 * 1e5)];

void solve_dp() {
    int n = nxt(), x = nxt();
    string str;
    cin >> str;
    int s[26];

    memset(s, 0, sizeof(s));
    for (int i = 0; i < x; i++) {
        char c;
        cin >> c;
        s[c - 'a'] = 1;
    }

    memset(space, 0, sizeof(space));

    // state: space[i] = number of substring ending at i

    // base condition
    if (s[str[0] - 'a']) space[0] = 1;
    ll total = space[0];
    for (int i = 1; i < n; i++) {
        if (!s[str[i] - 'a']) {
            space[i] = 0;
            continue;
        }
        space[i] = space[i - 1] + 1;  // recurrence
        total += space[i];
    }

    cout << total << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve_dp();
	}

	return 0;
}

