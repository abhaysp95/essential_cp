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

// Wrong solution
class Solution {
  using ll = long long;
public:
  ll get_length(vector<pair<ll, ll>>& pos, const string& s, int k, bool dir=true) {
    ll n=s.size();
    if (dir) {
      array<ll, 3> a={k, k, k};
      ll l=0,r=0;
      for (ll i=0; i<n; i++) {
        if (auto &x=a[s[i]-'a']; x!=0) {
          x--;
          auto &[o,t]=pos[i];
          if (o<=t || l+t>o) l=o;
          else if (o>t && r<t) r=t;
#ifdef NDEBUG
          cout << format("x: {}, c: {} o: {}, t: {}, l: {}, r: {}\n", x, s[i], o, t, l, r);
#endif
        }
      }
      for (auto &x: a) {
        if (x!=0) return -1;
      }
      return l+r;
    } else {
      array<ll, 3> a={k, k, k};
      ll l=0,r=0;
      for (ll i=n-1; i>=0; i--) {
        if (auto &x=a[s[i]-'a']; x!=0) {
          x--;
          auto &[o,t]=pos[i];
          if (t<=o || r+o>t) r=t;
          else if (t>o && l<o) l=o;
#ifdef NDEBUG
          cout << format("x: {}, c: {} o: {}, t: {}, l: {}, r: {}\n", x, s[i], o, t, l, r);
#endif
        }
      }
      for (auto &x: a) {
        if (x!=0) return -1;
      }
      return l+r;
    }
  }
  int takeCharacters(string s, int k) {
    if (k==0) return 0;
    vector<pair<ll, ll>> pos(s.size());
    ll n=s.size();
    for (ll i=0; i<n; i++) {
      auto &[o, t]=pos[i];
      o=i+1;
      t=n-i;
    }
#ifdef NDEBUG
    for (auto &[o, t]: pos) cout << o << ',' << t << " ";
    cout << '\n';
#endif
    ll fl=get_length(pos, s, k);
#ifdef NDEBUG
    cout << "----------\n";
#endif
    ll fr=get_length(pos, s, k, false);
    return min(fl, fr);
  }
};

void solve() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  Solution solve;
  cout << solve.takeCharacters(s, k) << '\n';
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

