#include <iostream>
#include <fstream>
#include <numeric>
#include <set>
#include <string>
#include <vector>
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

/**
 * the idea is that, a string with all single characters will have same amount
 * of distinct substrings which equals to the lenght of the string */
void solve() {
    int n = nxt();
    string s;
    cin >> s;

    if (n == 0) return;

    int l = 0, r = 0;

    vector<int> buc(26, 0);
    while (r < n) {
        if (s[l] != s[r]) {
            l = r;
        }
        buc[s[r] - 'a'] = max(buc[s[r] - 'a'], r - l + 1);
        r++;
    }

    // the above loop logic can also be written as follow
    /* int i = 0, j = 0;
    for (i = 0; i < n; i = j) {
        for (j = i; j < n && s[i] == s[j]; j++) {
            // ...
        }
    } */

    /* for (int i: buc) cout << i << " ";
    cout << '\n'; */

    // for (const string s: ss) cout << s << '\n';

    cout << accumulate(all(buc), 0) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

