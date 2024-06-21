#include <iostream>
#include <fstream>
#include <unordered_map>
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

void solve() {
    int n = nxt(), v = nxt();
    vector<int> voters(v), ans(v);

    for (int i = 0; i < v; i++) voters[i] = nxt();

    unordered_map<int, int> cand{};
    pair<int, int> maxp{0, -1};

    for (int i = 0; i < v; i++) {
        cand[voters[i]]++;
        if (maxp.second < cand[voters[i]]) {
            maxp.first = voters[i];
            maxp.second = cand[voters[i]];
        } else if (maxp.second == cand[voters[i]]) {
            maxp.first = min(maxp.first, voters[i]);
        }
        ans[i] = maxp.first;
    }

    for (int x: ans) cout << x << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

