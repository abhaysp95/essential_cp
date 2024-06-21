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

	int n = nxt();
	vector<array<int, 3>> data(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) data[i][j] = nxt();
	}

	sort(data.begin(), data.end(), [&](auto& a1, auto& a2) {
				return a1[0] < a2[0];
			});

	vector<int> buckets(data[0][2], 0);
	for (int i = 1; i < n; i++) {
		int bc = data[i][2];
		for (int j = 0; j < buckets.size(); j++) {
			if (data[buckets[j]][1] < data[i][0]) {
				buckets[j] = i;
				bc--;
			}
		}
		for (int j = 0; j < bc; j++) {
			buckets.push_back(i);
		}
		/* for (const int b: buckets) {
			cout << b << " ";
		}
		cout << '\n'; */
	}

	cout << buckets.size() << '\n';

	return 0;
}

/** input:
 * 3
 * 4 10 1
 * 8 13 3
 * 2 6 2
 */
