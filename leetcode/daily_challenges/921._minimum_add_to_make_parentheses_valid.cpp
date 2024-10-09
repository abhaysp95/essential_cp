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
  using ll = long long;
public:
  int minAddToMakeValid(string s) {
    ll o{}, c{};
    for (auto ch: s) {
      if (ch=='(') {
        o++;
      } else {
        if (o==0) c++;
        else o--;
      }
    }
    return o+c;
  }
};

void solve() {
  Solution solve{};
  string s;
  cin >> s;
  cout << solve.minAddToMakeValid(s) << endl;
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

