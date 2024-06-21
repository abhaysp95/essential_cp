#include <iostream>
#include <fstream>
#include <string>

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
    string s;
    cin >> s;

    string res{};

    int i = n - 1;
    string temp{};
    while (i > 0) {
        temp.clear();
        temp = "";
        if (s[i] == 'b' || s[i] == 'c' || s[i] == 'd') {
            temp += "." + s.substr(i - 2, 3);
            i -= 3;
        } else {
            temp += '.' + s.substr(i - 1, 2);
            i -= 2;
        }
        res = temp + res;
    }

    res = res.substr(1, res.size() - 1);

    cout << res << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

