#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
#include <unordered_map>
#include <unordered_set>
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

typedef struct _comparator {
    bool operator()(pair<int, int>& p1, pair<int, int>& p2) {
        return p1.first > p2.first;
    }
} comparator;

void solve() {
    int n = nxt();

    vector<vector<pair<int, int>>> mat(3);

    for (int i = 0; i < 3 * n; i++) {
        int j = i / n;
        mat[j].push_back({nxt(), i % n});
    }

    for (int i = 0; i < 3; i++) {
        sort(mat[i].begin(), mat[i].end(), [](pair<int, int>& p1, pair<int, int>& p2) {
                return p1.first > p2.first;
                });
    }

    int msum = -1;
    for (int xi = 0; xi < 3; xi++) {
        for (int yi = 0; yi < 3; yi++) {
            for (int zi = 0; zi < 3; zi++) {
                if (mat[0][xi].second != mat[1][yi].second
                        && mat[1][yi].second != mat[2][zi].second
                        && mat[0][xi].second != mat[2][zi].second) {
                    msum = max(msum, mat[0][xi].first + mat[1][yi].first + mat[2][zi].first);
                }
            }
        }
    }

    cout << msum << "\n";
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

