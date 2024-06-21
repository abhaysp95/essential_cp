#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int32_t main(void) {
	int n{};
	cin >> n;
	vector<int> arr(n);
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr.begin(), arr.end());
	int count = 0;
	for (int i = 1; i < n; i++) {
		if (arr[i - 1] != arr[i]) count++;
	}
	count++;
	cout << count << endl;
	return 0;
}
