#include <iostream>
#include <fstream>
#include <numeric>
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

void solve() {
    vector<long long> v{1, 1, 1};
    int N = nxt();

    int c = 1;
    unsigned long sum = 3;
    /* while (true) {
        if (c >= N) break;
        for (int i = 0; i < 3 && c < N; i++) {
            if (i == 0) {
                v[0] = v[i] * 10 + 1;
                v[1] = 1, v[2] = 1;
            } else {
                v[i] = v[i] * 10 + 1;
            }
            sum = accumulate(v.begin(), v.end(), 0);
            if (i == 2 && v[i] != v[0]) i = 0;
            c++;
        }
    } */

    /* int i = 0, j = 1, k = 2;
    while (true && c < N) {
        v[i] = v[i] * 10 + 1;
        c++;
        sum = accumulate(v.begin(), v.end(), 0);
        while (true && c < N) {
            if (v[j] == v[i]) {
                v[j] = 1;
                v[k] = 1;
                break;
            }
            v[j] = v[j] * 10 + 1;
            c++;
            sum = accumulate(v.begin(), v.end(), 0);
            while (true && c < N) {
                if (v[k] == v[j]) {
                    v[k] = 1;
                    break;
                }
                v[k] = v[k] * 10 + 1;
                c++;
                sum = accumulate(v.begin(), v.end(), 0);
            }
        }
    } */

    int i = 0, j = 0, k = 0;
    vector<long long> res{};
    res.push_back(3);
    for (i = 0; i <= 12; i++) {
        v[i] = v[i] * 10 + 1;
        v[j] = 0;
        for (j = 0; j < i; j++) {
            v[j] = v[j] * 10 + 1;
            v[k] = 0;
            for (k = 0; k < j; k++) {
                v[k] = v[k] * 10 + 1;
                res.push_back(v[i] + v[j] + v[k]);
            }
        }
    }

    cout << res[N] << endl;
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

