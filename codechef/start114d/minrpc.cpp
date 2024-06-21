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

string min_to_win(const string& moves, int idx, int mtow) {
    char cur = moves[idx];
    char wc, lc;
    if (cur == 'R') {
        wc = 'P', lc = 'S';
    } else if (cur == 'P') {
        wc = 'S', lc = 'R';
    } else wc = 'R', lc = 'P';

    string res;
    if (mtow <= idx) {
        res = min(min_to_win(moves, idx + 1, mtow)
                + lc, min_to_win(moves, idx + 1, mtow) + moves[idx]);
    }

    return (min_to_win(moves, idx + 1, mtow - 1) + wc, res);
}

/* void solve() {
    int n = 0;
    cin >> n;
    string moves{};
    cin >> moves;

    int mtow = (n % 2 == 0 ? n / 2 : (n - 1) / 2);

    cout << min_to_win(moves, 0, mtow) << '\n';
} */

void solve() {
    int n = 0;
    cin >> n;
    string dstr{};
    cin >> dstr;

    vector<char> wstr(n), lstr(n);

    for (int i = 0; i < n; i++) {
        char cur = dstr[i];
        if (cur == 'R') {
            wstr[i] = 'P', lstr[i] = 'S';
        } else if (cur == 'P') {
            wstr[i] = 'S', lstr[i] = 'R';
        } else wstr[i] = 'R', lstr[i] = 'P';
    }

    int mtow = (n % 2 == 0 ? n / 2 : (n - 1) / 2);

    vector<char> res(n);
    for (int i = 0; i < n; i++) {
        if (n - i - 1 > mtow) {
            char sel = min(wstr[i], min(lstr[i], dstr[i]));
            if (sel == wstr[i]) mtow--;
            res[i] = sel;
        } else {
            res[i] = wstr[i];
            mtow--;
        }
    }

    for (const char c: res) {
        cout << c;
    }
    cout << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

