#include <ios>
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include <string>

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cerr.tie(nullptr);

	int m = nxt(), n = nxt(), k = nxt();
	vector<string> res;

	for (int i = 0; i < m; i++) {
		string input;
		cin >> input;

		string amp{};
		for (int c = 0; c < n; c++) {
			amp += string(k, input[c]);
		}
		for (int j = 0; j < k; j++) res.push_back(amp);
	}

	for (const string s: res) {
		cout << s << '\n';
	}

	return 0;
}

/** input:
 * 5 4 2
 * XXX.
 * X..X
 * XXX.
 * X..X
 * XXX.
 */
