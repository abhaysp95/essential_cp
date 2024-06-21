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

	array<int, 100> allowed{};
	array<int, 100> actual{};

	int n = nxt(), m = nxt();
	int td = 0;
	for (int i = 0; i < n; i++) {
		int d = nxt(), s = nxt();
		for (int i = 0; i < d; i++) allowed[td + i] = s;
		td += d;
	}
	td = 0;
	for (int i = 0; i < m; i++) {
		int d = nxt(), s = nxt();
		for (int i = 0; i < d; i++) actual[td + i] = s;
		td += d;
	}

	int maxs = 0;
	for (int i = 0; i < 100; i++) {
		maxs = max(maxs, actual[i] - allowed[i]);
	}

	cout << maxs << '\n';

	return 0;
}

/*
"xyyyz"
"xzyz"
"zzz"
Output: "xyyyzyzz"
Expected: "xyyyzxzyzzz" */
