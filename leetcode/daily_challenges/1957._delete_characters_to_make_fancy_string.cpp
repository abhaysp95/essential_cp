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
  string makeFancyString(string s) {
    string ns(s.size(), '\0');
    ll k=0;
    char p='\0';
    for (ll i=0,ct=0; i<s.size(); i++,ct++) {
      if (p!=s[i]) {
        ct=0;
        p=s[i];
      } else if (ct==2) {
        ll j=i;
        for (;j<s.size()&&p==s[j]; j++) {}
        i=j-1;
        ct=0;
        continue;
      }
      ns[k++]=s[i];
    }
    return ns.substr(0, k);
  }
};

void solve() {
  Solution solve;
  string s;
  getline(cin, s);
  cout << solve.makeFancyString(s) << endl;
}

int32_t main(void) {
	FAST_IO;

	int T = nxt();
  cin.ignore(1, '\n'); // or else first sent string is empty string by getline
	while (T--) {
		solve();
	}

	return 0;
}

