#include <algorithm>
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


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

// find element in rotated sorted array
// not correct (fails some tests)
/* int find_element(const vector<int>& vec, int key) {
    int n = sz(vec);
    int l = 0, r= n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (vec[mid] == key) return mid;

        if (vec[mid] > key) {
            if (vec[l] < key) r = mid - 1;
            else l = mid + 1;
        } else if (vec[mid] < key) {
            if (vec[r] < key) r = mid - 1;
            else l = mid + 1;
        }
    }

    return 0;
} */

int find_smallest(const vector<int>& vec) {
    int n = sz(vec);
    int l = 0, r = n - 1;

    if (vec[l] < vec[r]) return 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        int left = (mid - 1 + n ) % n;
        int right = (mid + 1) % n;
        if (vec[left] > vec[mid] && vec[mid] < vec[right]) return mid;

        if (vec[l] > vec[mid] || vec[mid] > vec[r]) l = mid + 1;  // uneven
        else r = mid - 1;
    }

    return -1;
}

int bin_search(const vector<int>& vec, int i, int j, int key) {
    int l = i, r = j - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if (vec[mid] == key) return mid;
        if (vec[mid] < key) l = mid + 1;
        else r = mid - 1;
    }

    return -1;
}

int find_element(const vector<int>& vec, int key) {
    int pivot = find_smallest(vec);
    int n = sz(vec);
    if (vec[0] <= key && vec[pivot - 1] >= key) {
        return bin_search(vec, 0, pivot, key);
    } else if (vec[pivot] <= key && vec[n - 1] >= key) {
        return bin_search(vec, pivot, n, key);
    }

    return -1;  // not found
}

void solve() {
    vector<int> vec{10, 11, 12, 15, 18, 2, 5, 6, 8, 9};
    // vector<int> vec{2, 3, 4, 5, 1};
    cout << find_element(vec, 18) << '\n';
    cout << find_element(vec, 9) << '\n';
    cout << find_element(vec, 10) << '\n';
    cout << find_element(vec, 2) << '\n';
    cout << find_element(vec, 6) << '\n';
    cout << find_element(vec, 12) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

