#include <algorithm>
#include <iostream>
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

// NOTE: return value -1 would mean that key is not present and is less than the
// first element of the provided sorted array
int get_floor(const vector<int>& vec, int key) {
    int n = sz(vec);
    int l = 0, r = n - 1;

    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (vec[mid] == key) return mid;
        if (vec[mid] > key) {
            r = mid - 1;
            ans = mid;
        } else l = mid + 1;
    }

    if (ans == -1) return ans;

    return ans - 1;  // because we have to return floor (not lower bound)
}

int get_ceil(const vector<int>& vec, int key) {
    int n = sz(vec);
    int l = 0, r = n - 1;

    int ans = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (vec[mid] == key) return mid;
        if (vec[mid] < key) {
            l = mid + 1;
            ans = mid;
        } else r = mid - 1;
    }

    return ans + 1;
}

void solve() {
    vector<int> vec{1, 2, 3, 4, 8, 10, 10, 12, 19};
    int key = nxt();

    cout << get_floor(vec, key) << '\n';
    cout << get_ceil(vec, key) << '\n';
    cout << *lower_bound(all(vec), key) << '\n';
    cout << distance(vec.begin(), lower_bound(all(vec), key)) << '\n';
    cout << distance(vec.begin(), upper_bound(all(vec), key)) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

