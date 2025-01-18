#include <bits/stdc++.h>
#include <lc_list.hpp>

using namespace std;

#define uint unsigned int
// #define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

class Solution {
  using ll=long long;
public:
  int scoreOfString(string s) {
    ll sum=0;
    for (ll i=0; i<s.size()-1; i++) {
      sum+=abs(int(s[i])-int(s[i+1]));
    }
    return sum;
  }
};

void solve() {

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

