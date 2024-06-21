#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

int32_t main(void) {
	int n = 0, m = 0, k = 0;
	cin >> n >> m >> k;

	vector<int> ds(n), as(m);
	for (int i = 0; i < n; i++) cin >> ds[i];
	for (int i = 0; i < m; i++) cin >> as[i];

	sort(ds.begin(), ds.end());
	sort(as.begin(), as.end());

	int count = 0;
	int dsc = 0, asc = 0;
	while (dsc < n) {
		bool incr = true;
		for (int i = -(k - 1); i < k; i++) {
			if (ds[dsc] == as[asc] + i) {
				count++;
				incr = false;
				break;
			}
		}
		if (incr && as[asc] < ds[dsc]) asc++;
		dsc++;
	}

	cout << count << '\n';

	return 0;
}
