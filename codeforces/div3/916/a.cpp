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
    unordered_map<char, int> umap{};

    for (int i = 0; i < 26; i++) {
        umap['A' + i] = i + 1;
    }

    int time = nxt();
    string ques;
    cin >> ques;

    for (int i = 0; i < ques.size(); i++) {
        if (umap[ques[i]] != 0) umap[ques[i]]--;
    }

    int total = 0;
    for (const pair<const char, int>& p: umap) {
        if (p.second == 0) total++;
    }

    cout << total << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

