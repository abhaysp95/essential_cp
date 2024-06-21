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

	int N = nxt();
	vector<int> swaps(N, 0);
	for (int i = 0; i < N; i++) swaps[i] = nxt();
	vector<int> cows(N, 0);
	for (int i = 0; i < N; i++) cows[i] = nxt();

	for (int i = 0; i < 3; i++) {
		vector<int> temp(N);
		for (int i = 0; i < N; i++) {
			temp[i] = cows[swaps[i] - 1];
		}
		cows = std::move(temp);
	}

	for (const int cow: cows) {
		cout << cow << '\n';
	}

	return 0;
}

/** input:
 * 5
 * 1 3 4 5 2
 * 1234567 2222222 3333333 4444444 5555555
 */
