#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
// #define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

/**
  * Things to remember:
  * Problem says to convert s to goal
  * You can ask to interviewer:
  * Can s and goal have different length as input ?
  * Is rotation count of 0 considered as valid rotation ?
  */

class Solution {
  using ll = long long;
public:
  bool rotateString(string s, string goal) {
    if (s.size()!=goal.size()) return false;
    auto ns = s + s;
    return ns.find(goal) != string::npos ? true : false;
  }
};


void solve() {
  Solution solve;
  string s, goal;
  cin >> s >> goal;
  cout << solve.rotateString(s, goal) << endl;
}

int32_t main(void) {
  FAST_IO;

	// int T;
 //  cin >> T;
	// while (T--) {
		solve();
	// }

	return 0;
}

