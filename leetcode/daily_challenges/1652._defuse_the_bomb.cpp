#include <bits/stdc++.h>
#include "../lc_list.hpp"

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
  vector<int> decrypt(vector<int>& code, int k) {
    vector<int> res(code.size());
    for (ll i=0; i<code.size(); i++) {
      if (k==0) {
        res[i]=0;
      } else if (k>0) {
        ll sum=0;
        for (ll j=1; j<=k; j++) {
          sum+=code[(i+j)%code.size()];
        }
        res[i]=sum;
      } else {
        ll sum=0;
        for (ll j=1; j<=abs(k); j++) {
          sum+=code[(code.size()+i-j)%code.size()];
#ifdef NDEBUG
          cout << format("i: {}, j: {}, sum: {} | ", i, j, sum);
#endif
        }
        res[i]=sum;
#ifdef NDEBUG
        cout << format("res[{}]: {}\n", i, res[i]);
#endif
      }
    }
    return res;
  }
};

void solve() {
  string s;
  cin >> s;
  vector<int> code = read_vector<int>(s);
  int k;
  cin >> k;
  Solution solve{};
  vector<int> res = solve.decrypt(code, k);
  for (auto &x: res) cout << x << ' ';
  cout << endl;
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

