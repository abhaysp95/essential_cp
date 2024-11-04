#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
// #define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

class Solution {
  using ll = long long;
public:
  string compressedString(string word) {
    string comp{};
    char p='\0';
    ll c=0;
    for (ll i=0; i<word.size();i++,c++) {
      if (p!=word[i]||c==9) {
        if (p!='\0') comp += to_string(c) + p;
        p=word[i];
        c=0;
      }
    }
    comp += to_string(c) + p;
    return comp;
  }
};

void solve() {
  Solution solve;
  string s;
  cin >> s;
  cout << solve.compressedString(s) << endl;
}

int32_t main(void) {
  FAST_IO;

	int T;
  cin >> T;
	while (T--) {
		solve();
	}

	return 0;
}

