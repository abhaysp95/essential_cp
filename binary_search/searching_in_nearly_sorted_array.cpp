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

// nearly sorted means, vec[i] can either be swapped with vec[i - 1] or vec[i + 1]

int find_element(const vector<int>& vec, int key) {
    int n = sz(vec) - 1;
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (vec[mid] == key) return mid;
        if (vec[mid] != 0 && vec[mid - 1] == key) return mid - 1;
        if (vec[mid] != n - 1 && vec[mid + 1] == key) return mid + 1;

        if (vec[mid] > key) r = mid - 2;
        else l = mid + 2;
    }

    return -1;
}

void solve() {
    vector<int> vec{5, 10, 30, 20, 40};
    cout << find_element(vec, 5) << '\n';
    cout << find_element(vec, 10) << '\n';
    cout << find_element(vec, 20) << '\n';
    cout << find_element(vec, 30) << '\n';
    cout << find_element(vec, 40) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

