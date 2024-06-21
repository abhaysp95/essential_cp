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


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

int partition_point_old(const vector<int>& vec) {
    int l = 0, r = sz(vec) - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;  // this method helps in integer overflow
        if ((mid > 0 && vec[mid - 1] > vec[mid])
                && (mid < sz(vec) - 1 && vec[mid] < vec[mid + 1])) {
            return mid;
        }
        if (mid == 0 && vec[mid] < vec[mid + 1]) return mid;
        if (mid == sz(vec) - 1 && vec[mid] < vec[mid - 1]) return mid;

        if (vec[l] > vec[r]) {  // uneven
            l = mid + 1;
        } else r = mid - 1;
    }

    return 0;
}

int partition_point(const vector<int>& vec) {
    int n = sz(vec);
    int l = 0, r = sz(vec) - 1;
    if (vec[l] < vec[r]) return 0;

    while (l <= r) {
        int mid = l + (r - l) / 2;  // this method helps in integer overflow
        int prev = (mid - 1 + n) % n, next = (mid + 1) % n;
        if (vec[prev] > vec[mid] && vec[mid] < vec[next]) return mid;

        if (vec[l] > vec[mid] || vec[mid] > vec[r]) {  // uneven
            l = mid + 1;
        } else r = mid - 1;
    }

    return 0;
}

void solve() {
    vector<int> vec{10, 11, 12, 15, 18, 2, 5, 6, 8, 9};
    // vector<int> vec{2, 3, 4, 5, 1};
    cout << partition_point(vec) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

