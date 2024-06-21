#include <ios>
#include <iostream>
#include <vector>
#include <array>

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cerr.tie(nullptr);

	int N = nxt();
	vector<array<int, 3>> moves(N, array<int, 3>{});
	for (int i = 0; i < N; i++) {
		moves[i][0] = nxt();
		moves[i][1] = nxt();
		moves[i][2] = nxt();
	}

	int maxc = 0;
	for (int k = 1; k <= 3; k++) {
		int cur = k;
		int count = 0;
		for (int i = 0; i < N; i++) {
			if (moves[i][0] == cur) cur = moves[i][1];
			else if (moves[i][1] == cur) cur = moves[i][0];
			if (moves[i][2] == cur) count++;
		}
		maxc = max(maxc, count);
	}

	cout << maxc << '\n';

	return 0;
}

/** input:
 * 3
 * 1 2 1
 * 3 2 1
 * 1 3 1
 */
