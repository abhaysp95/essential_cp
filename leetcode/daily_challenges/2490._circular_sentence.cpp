#include <algorithm>
#include <bits/stdc++.h>
#include <string>

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
  bool isCircularSentence(string sentence) {
    if (sentence[0] != sentence[sentence.size() - 1]) {
      return false;
    }
    for (auto iter = find(sentence.begin(), sentence.end(), ' ');
         iter != sentence.end(); iter = find(iter+1, sentence.end(), ' ')) {
      if (*(iter - 1) != *(iter + 1)) {
        return false;
      }
    }
    return true;
  }
};

void solve() {
  Solution solve;
  string s;
  getline(cin, s);
  cout << solve.isCircularSentence(s) << endl;
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

