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

	array<int, 3> cap{};
	array<int, 3> amt{};

	for (int i = 0; i < 3; i++) {
		cap[i] = nxt(), amt[i] = nxt();
	}

	int a = 0, b = 1;
	for (int i = 0; i < 100; i++) {
		int amount = min(amt[a], cap[b] - amt[b]);
		amt[a] -= amount;
		amt[b] += amount;

		a = (a + 1) % 3, b = (b + 1) % 3;
	}

	for (const int x: amt) cout << x << '\n';

	return 0;
}

/** input
 * 10 3
 * 11 4
 * 12 5
 */
