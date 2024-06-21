#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
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
    string s1, s2;
    cin >> s1;
    cin >> s2;
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    unordered_map<string, int> umap{
        {"AB", 1},
        {"BC", 1},
        {"CD", 1},
        {"DE", 1},
        {"AE", 1},
        {"AC", 2},
        {"AD", 2},
        {"BE", 2},
        {"BD", 2},
        {"CE", 2},
    };

    int d1 = umap.find(s1)->second;
    int d2 = umap.find(s2)->second;

    cout << (d1 == d2 ? "Yes" : "No")  << endl;
}

int32_t main() {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

