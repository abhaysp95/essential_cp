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
#include <cstring>
#include <iterator>
#include <algorithm>
#include <functional>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define INF (int)1e9

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

inline ll nxt(istream& cin = std::cin) {
	ll x;
	cin >> x;
	return x;
}

class Solution {
    vector<vector<int>> space;

    public:
    int longest_common_subsequence_pushdp(string text1, string text2) {
		int a = text1.size(), b = text2.size();
        space.resize(a + 1, vector<int>(b + 1, 0));

        for (ll i = 0; i < a; i++) {
            for (ll j = 0; j < b; j++) {
                if (text1[i] == text2[j]) space[i + 1][j + 1] = space[i][j] + 1;
                else space[i + 1][j + 1] = max(space[i + 1][j], space[i][j + 1]);
            }
        }

		for (ll i = 0; i <= a; i++) {
			for (ll j = 0; j <= b; j++) cout << space[i][j] << " ";
			cout << '\n';
		}

        return space[a][b];
    }

    int longestCommonSubsequence_pulldp(string text1, string text2) {
		int a = text1.size(), b = text2.size();
		space.resize(a + 1, vector<int>(b + 1, 0));

		for (int i = 1; i <= a; i++) {
			for (int j = 1; j <= b; j++) {
				if (text1[i - 1] == text2[j - 1]) space[i][j] = space[i - 1][j - 1] + 1;
				else space[i][j] = max(space[i - 1][j], space[i][j - 1]);
			}
		}

		return space[a][b];
	}

	int longestCommonSubsequenceCaching(string text1, string text2) {
		int a = text1.size(), b = text2.size();
		space.resize(a, vector<int>(b, -1));

		function<int(int x, int y)> lcs = [&](int x, int y) -> int {
			if (x >= a || y >= b) return 0;

			if (space[x][y] != -1) return space[x][y];

			int length = 0;
			if (text1[x] == text1[y]) {
				length = 1 + lcs(x + 1, y + 1);
			} else length = max(lcs(x + 1, y), lcs(x, y + 1));

			return space[x][y] = length;
		};

		return lcs(0, 0);
	}

	string retreive_longest_common_subsequence(string text1, string text2) {
		string res{};

		int i = text1.size(), j = text2.size();
		while (i > 0 && j > 0) {
			if (text1[i - 1] == text2[j - 1]) {
				res += text1[i - 1];
				i--, j--;
			} else {
				if (space[i - 1][j] > space[i][j - 1]) i--;
				else j--;
			}
		}

		// reverse(res.begin(), res.end());
		int sz = res.size();
		for (int i = 0; i < sz / 2; i++) {
			char temp = res[i];
			res[i] = res[sz - i - 1];
			res[sz - i - 1] = temp;
		}

		return res;
	}
};

void solve() {
    string s1, s2;
    cin >> s1 >> s2;

    Solution solve;
    cout << solve.longest_common_subsequence_pushdp(s1, s2) << '\n';
    cout << solve.retreive_longest_common_subsequence(s1, s2) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

