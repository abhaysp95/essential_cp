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

  ll get_max_unique_subs(vector<ll>& pat, const string& s) {
    // for (auto &x: pat) cout << x << ' ';
    // cout << '\n';
    ll n=pat.size();
    set<string> st;
    ll prev=-1, ci=0, cl=0;
    for (ll i=0; i<n; i++) {
      if (prev!=pat[i]) {
        // make new_sub
        if (cl!=0) {
          st.insert(s.substr(ci, cl));
          ci=i;
          cl=0;
        }
        prev=pat[i];
      }
      cl++;
    }
    if (cl!=0 && ci+cl<=n) st.insert(s.substr(ci, cl));
    // for (auto &x: st) cout << x << ' ';
    // cout << '\n';
    return st.size();
  }
public:
  int maxUniqueSplit(string s) {
    ll n = s.size();
    ll msubs = 0;
    for (ll m=0; m<(1<<n); m++) {
      vector<ll> pat(n);
      fill(pat.begin(), pat.end(), 0);
      for (ll j=0; j<n; j++) {
        if (m&(1<<j)) {
          pat[j]=1;
        } else {
          pat[j]=0;
        }
      }
      msubs = max(msubs, get_max_unique_subs(pat, s));
    }
    return msubs;
  }
};

void solve() {
  string s;
  cin >> s;
  Solution solve;
  cout << solve.maxUniqueSplit(s) << '\n';
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

