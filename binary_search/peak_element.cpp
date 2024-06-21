#include <iostream>
#include <fstream>
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


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

int peak_element(const vector<int>& vec) {
    int n = sz(vec);
    if (n == 1) return 0;
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if ((mid == 0 && vec[mid] > vec[mid + 1])
                || (mid == n - 1 && vec[mid] > vec[mid - 1])
                || (vec[mid] > vec[mid + 1] && vec[mid] > vec[mid - 1])) return mid;

        if (vec[mid - 1] > vec[mid]) {
            r = mid - 1;
        } else l = mid + 1;
    }

    return -1;
}

int trench_element(const vector<int>& vec) {
    int n = sz(vec);
    if (n == 1) return 0;
    int l = 0, r = n - 1;

    while (l <= r) {
        int mid = l + (r - l) / 2;

        if ((mid == 0 && vec[mid] < vec[mid + 1])
                || (mid == n - 1 && vec[mid] < vec[mid - 1])
                || (vec[mid] < vec[mid - 1] && vec[mid] < vec[mid + 1])) return mid;

        if (vec[mid - 1] < vec[mid]) r = mid - 1;
        else l = mid + 1;
    }

    return -1;
}

void solve() {
    // vector<int> vec{10, 20, 15, 2, 23, 90, 67};
    vector<int> vec{10, 25, 20, 20, 20, 15, 2, 2, 23, 23, 90, 67};

    cout << vec[peak_element(vec)] << '\n';
    cout << vec[trench_element(vec)] << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

