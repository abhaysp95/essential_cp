#include <bits/stdc++.h>
#include <format>
#include <stack>

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
  int minLength(string s) {
    stack<char> st{};
    for (ll i=0; i<s.size(); i++) {
      if (!st.empty()) {
        if ((st.top()=='A' && s[i]=='B')
          || (st.top()=='C' && s[i]=='D')) {
          st.pop();
        } else st.push(s[i]) ;
      } else st.push(s[i]);
    }
    return st.size();
  }
};


class SolutionBruteForce {
  using ll = long long;

public:
  int minLength(string s) {
    while (true) {
      bool found=false;
      if (ll idx=s.find("AB"); idx != string::npos) {
        s = s.substr(0, idx) + ((idx+2<=s.size()) ? s.substr(idx+2, s.size()-(idx+2)) : "");
        found = true;
        cout << s << '\n';
      }
      if (ll idx=s.find("CD"); idx != string::npos) {
        s = s.substr(0, idx) + ((idx+2<=s.size()) ? s.substr(idx+2, s.size()-(idx+2)) : "");
        found = true;
        cout << s << '\n';
      }
      if (!found) break;
    }
    return s.size();
  }
};

void solve() {
  Solution solve{};
  string str;
  cin >> str;
  cout << format("len: {}\n", solve.minLength(str));
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

