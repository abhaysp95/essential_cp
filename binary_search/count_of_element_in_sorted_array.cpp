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

// returns index (lower bound)
int kinda_lower_bound(const vector<int>& vec, int k) {
    int l = 0, r = sz(vec);
    int mpos = sz(vec);
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (vec[mid] >= k) {
            r = mid - 1;
            mpos = mid;
        } else l = mid + 1;
    }

    return mpos;
}

int kinda_upper_bound(const vector<int>& vec, int k) {
    int l = 0, r = sz(vec);
    int mpos = 0;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (vec[mid] > k) {
            r = mid - 1;
        } else {
            l = mid + 1;
            mpos = mid;
        }
    }

    return mpos;
}

void solve() {
    vector<int> vec = {1, 3, 4, 5, 5, 5, 7, 8};

    int spos = kinda_lower_bound(vec, 5);
    int epos = kinda_upper_bound(vec, 5);

    cout << epos - spos + 1 << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

