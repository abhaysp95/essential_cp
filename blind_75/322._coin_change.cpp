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
  using ll=long long;
  vector<ll> space;
public:
  int coin_count(vector<int>& coins, int amount) {
    if (amount==0) return 0;
    if (this->space[amount]!=-1) return this->space[amount];
    ll min_coins=1e9;
    for (ll i=0; i<coins.size(); i++) {
      if (amount-coins[i]>=0) {
        min_coins=min((int)min_coins,1+coin_count(coins, amount-coins[i]));
      }
    }
    return this->space[amount]=min_coins;
  }
  int coinChange(vector<int>& coins, int amount) {
    this->space.resize(amount+1, -1);
    ll ret=coin_count(coins, amount);
    return ret==1e9?-1:ret;
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

