#include <ios>
#include <iostream>
#include <vector>

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
	vector<int> cap(N, 0);
	vector<int> filled(N, 0);
	for (int i = 0; i < N; i++) {
		cap[i] = nxt();
	}
	for (int i = 0; i < N; i++) {
		filled[i] = nxt();
	}

	for (int i = 0; i + 1 < N; i++) {
		/* int left = cap[i + 1] - filled[i + 1];
		if (left >= filled[i]) {
			filled[i + 1] += filled[i], filled[i] = 0;
		} else {
			filled[i] -= left, filled[i + 1] = cap[i + 1];
		} */
		int amount = min(filled[i], cap[i + 1] - filled[i + 1]);
		filled[i] -= amount;
		filled[i + 1] += amount;
	}

	for (const int x: filled) {
		cout << x << " ";
	}
	cout << '\n';

	return 0;
}
