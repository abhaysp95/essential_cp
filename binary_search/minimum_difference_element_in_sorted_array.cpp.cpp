#include <iostream>
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


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int min_diff_element(const vector<int>& arr, int key) {
    int n = sz(arr);
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (arr[mid] > key) r = mid - 1;
        else l = mid + 1;
    }

    int a = abs(arr[l] - key), b = abs(arr[r] - key);
    return a > b ? arr[r] : arr[l];
}

void solve() {
    vector<int> arr{1, 3, 8, 10, 12, 15};
    int key = nxt();

    cout << min_diff_element(arr, key) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

