#include <bits/stdc++.h>
#include <lc_list.hpp>

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
  int maxProfit(vector<int>& prices) {
    ll mprofit=0;
    ll i=0, j=1;
    while (j<prices.size()) {
      mprofit=max((int)mprofit, prices[j]-prices[i]);
      if (prices[j]>prices[i]) j++;
      else i=j,j++;
    }
    return mprofit;
  }

  // this doesn't work for test cases like: [0,1,2,0,1]
  int maxProfit_initial(vector<int>& prices) {
    ll mprofit=0;
    ll dip=-1, tip=prices.size();
    while (dip<tip) {
      dip++;
      for (ll i=dip; i<prices.size()-1; i++) {
        if (prices[i]<prices[i+1] && (dip==-1 || prices[dip]>=prices[i])) {
          dip=i;
          break;
        }
      }
      tip--;
      for (ll i=tip; i>0; i--) {
        if (prices[i]>prices[i-1] && (tip==-1 || prices[tip]<=prices[i])) {
          tip=i;
          break;
        }
      }
#ifdef NDEBUG
      dbg(dip);
      dbg(tip);
#endif
      if (dip>=tip || (dip==-1||tip==-1)) {
        break;
      }
      mprofit=max((int)mprofit, prices[tip]-prices[dip]);
#ifdef NDEBUG
      dbg(mprofit);
#endif
    }
    return mprofit;
  }
};

void solve() {
  string s;
  cin >> s;
  vector<int> arr = read_vector<int>(s);
  Solution solve{};
  cout << solve.maxProfit(arr) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
	while (T--) {
		solve();
	}

	return 0;
}

