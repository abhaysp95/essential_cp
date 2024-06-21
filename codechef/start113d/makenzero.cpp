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

bool canzero(int n, int s) {
    if (n == s) return true;
    if (n < s) return false;

    return canzero(n, s + 3) || canzero(n, s + 4);
}

void solve() {
    int n = nxt();

    cout << (canzero(n, 0) ? "yes" : "no")  << '\n';
}

void solve2() {
    vector<int> v {0, 0, 1, 1, 0, 1, 1, 1, 1};

    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        while (N >= 10) N -= 3;
        cout << (v[N - 1] == 1 ? "yes" : "no") << '\n';
    }
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

