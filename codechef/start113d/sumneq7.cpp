// https://www.codechef.com/problems/SUMNEQ7

#include <iostream>
#include <fstream>
#include <set>
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

/* void solve() {
    int n = nxt();
    vector<int> arr(n);

    for (int i = 0; i < n; i++) arr[i] = nxt();

    set<int> aset{}, bset{};
    for (int i = 0; i < (n + 1) / 2; i++) {
        for (int j = i + 1; j < (n + 1) / 2; j++) aset.insert(arr[i] + arr[j]);
    }

    for (int i = (n + 1) / 2; i < n; i++) {
        for (int j = i + 1; j < n; j++) bset.insert(arr[i] + arr[j]);
    }

    if (aset.size() != bset.size()) {
        cout << "yes" << '\n';
    } else {
        for (auto aiter = aset.begin(), biter = bset.begin(); aiter != aset.end(); aiter++, biter++) {
            if (*aiter != *biter) {
                cout << "yes" << '\n';
                return;
            }
        }
    }

    cout << "no" << '\n';
} */

void solve() {
    int n = nxt();
    vector<int> arr(n);

    for (int i= 0; i < n; i++) arr[i] = nxt();

    if (n == 4) {
        if (arr[0] + arr[1] != arr[2] + arr[3]) {
            cout << "yes" << '\n';
        } else cout << "no" << '\n';
        return;
    }

    unordered_map<int, int> umap{};
    for (int i = 0; i < 4; i++) umap[arr[i]]++;
    int l = 0, r = 4;
    while (r < n) {
        umap[arr[r++]]++;
        if (umap.size() > 1) {
            cout << "yes" << '\n';
            return;
        }
        umap[arr[l]]--;
        if (umap[arr[l]] == 0) umap.erase(arr[l]);
        l++;
    }

    cout << "no" << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

