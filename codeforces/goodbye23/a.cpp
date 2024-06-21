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

vector<int> fact;

void solve() {
    int n = nxt(), k = nxt();

    int pr = 1;
    for (int i = 0; i < n; i++) pr *= nxt();

    bool found = false;
    int left = 0;
    for (int i = 0; i < fact.size(); i++) {
        if (fact[i] == pr) {
            found = true;
            left = 2023 / pr;
        }
    }
    if (!found) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    vector<int> ans{};
    ans.push_back(2023 / pr);

    while(k--) {
        ans.push_back(1);
    }

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}

void solve2() {
    int n = nxt(), k = nxt();

    int left = 2023;
    bool possible = true;
    for (int i = 0; i < n; i++) {
        int x = nxt();
        possible &= (left % x == 0);
        left /= x;
    }

    if (!possible) {
        cout << "NO" << '\n';
        return;
    }

    cout << "YES" << '\n';
    cout << left << ' ';

    while (k-- != 1) {
        cout << 1 << ' ';
    }
    cout << '\n';
}

int32_t main(void) {
	FAST_IO;

    /* for (int i = 0; i <= 2023; i++) {
        if (2023 % i == 0) {
            // cout << i << '\n';
            fact.push_back(i);
        }
    } */

	int T = nxt();
	while (T--) {
		solve2();
	}

	return 0;
}

