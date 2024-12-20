#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
// #define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

class Solution {
public:
  int recurse(int n) {
    if (n<=1) {
      return 1;
    }
    return recurse(n-1) + recurse(n-2);
  }

  int climbStairs(int n) {
    ll steps[2] = {1, 1};
    for (ll i=2; i<=n; i++) {
      ll t=steps[0]+steps[1];
      steps[0]=steps[1];
      steps[1]=t;
    }
    return steps[1];
  }
};

void solve() {
	// type here
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

