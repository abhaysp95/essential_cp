#include <algorithm>
#include <iostream>
#include <iterator>
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


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

/* void solve() {
    int n = nxt();
    vector<int> arr(n);
    vector<int> idx;

    bool same = true;
    int x = nxt();
    int mi = x;
    arr[0] = x;
    bool push = true;
    for (int i = 1; i < n; i++) {
        int x = nxt();
        arr[i] = x;
        if (arr[i - 1] != arr[i]) same = false;
        if (mi > x) {
            mi = x;
            push = true;
        }
        if (mi < x && push) {
            push = false;
            // cout << i - 1 << " - ";
            idx.push_back(i - 1);
        }
    }
    // cout << "\n";

    if (idx.empty()) {
        if (same) {
            cout << (arr[0] > n ? n : arr[0]) << '\n';
            return;
        }
        cout << n << '\n';
        return;
    }

    int maxi = -1;
    for (int i = 0; i < sz(idx); i++) {
        maxi = max(maxi, arr[idx[i]]);
    }

    int count = maxi;
    // cout << "init count: " << count << '\n';
    for (int i = 0; i < n; i++) {
        if (arr[i] > maxi) count++;
    }

    // cout << count << "\n---------\n";
    cout << count << '\n';
} */

void solve() {
    unordered_map<int, vector<int>> umap;
    set<int> unum;  // this will keep all unique nums sorted

    int n = nxt();
    for (int i = 0; i < n; i++) {
        int x = nxt();
        umap[x].push_back(i);
        unum.insert(x);
    }

    int last = n;
    int total = 0;
    int ans = n;
    for (auto num: unum) {
        auto esafe = upper_bound(all(umap[num]), last - 1);
        // the below means, that the safe range is already lower than the first
        // index of element num in the array, thus upper_bound will give that
        // first idx of num, but since it shouldn't be taken, we'll ignore it
        // and 'continue'
        if (esafe == umap[num].begin()) continue;
        int count = distance(umap[num].begin(), esafe);
        last = *umap[num].begin();
        total += count;
        ans = min(ans, n - total + num);
    }

    cout << ans << "\n";
}


int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

