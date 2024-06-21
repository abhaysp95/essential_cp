#include <iostream>

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

int32_t main(void) {
	int r = nxt(), s = nxt(), m = nxt(), n = nxt(), p = nxt(), q = nxt();
	int a = 0, b = 0;

	int count = 0;
	while (true) {
		a += m, b += n;
		r -= p, s -= q;

		if (a == r && b == s) {
			break;
		} else if (a > r || b > s) {
			count =-1;
			break;
		}
		count++;
	}

	cout << count << endl;

	return 0;
}
