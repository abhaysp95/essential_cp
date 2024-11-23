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

// NOTE: get good with implementation & ad-hoc problems
// practice more grid based problems
// this one took some tries to get it done
class Solution {
  using ll = long long;
public:
  vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
    ll m=box.size(), n=box[0].size();
    vector<vector<char>> tv(n, vector<char>(m, '.')); // turned vector
    // fill the '*'
    for (ll r=0; r<m; r++) {
      for (ll c=0; c<n; c++) {
        if (box[r][c]=='*') tv[c][m-r-1]=box[r][c];
      }
    }
#ifdef NDEBUG
    for (auto &x: tv) {
      for (auto &c: x) cout << c << ' ';
      cout << '\n';
    }
#endif
    for (ll r=m-1; r>=0; r--) {
      for (ll c=n-1; c>=0; c--) {
        if (box[r][c]=='#') {
          ll tr=c,tc=m-r-1;
#ifdef NDEBUG
          cout << format("r: {}, tr: {}, c: {}, tc: {}", r, tr, c, tc);
#endif
          ll d=tr;
          for (; d+1<n; d++) if (tv[d+1][tc]!='.') break;
          tv[d][tc]=box[r][c];
#ifdef NDEBUG
          cout << format("d: {}\n", d);
#endif
          for (ll x=tr; x<d; x++) box[r][x]='.';
#ifdef NDEBUG
          for (auto &x: tv) {
            for (auto &c: x) cout << c << ' ';
            cout << '\n';
          }
          cout << "~~~~~~~~~~~~~~~\n";
#endif
        }
      }
    }
    return tv;
  }
};

void solve() {
  string str;
  cin >> str;
  std::vector<std::vector<char>> arr{};
  ASSERT_MSG(str[0] == '[', "Argument format should be [[1,2],[3],...]");
  str = str.substr(1,str.size()-1);
  std::istringstream istream{str};
  for (std::string s{}; getline(istream, s, ']');) {
    if (s.empty()) continue;
    std::vector<char> vec{};
    if (s[0]=='[') s = s.substr(1, s.size()-1);
    else if (s[0]==',') s = s.substr(2, s.size()-2);
    std::istringstream i2stream{s};
    for (std::string s2{}; getline(i2stream, s2, ',');) {
      if (s2.empty()) continue;
      vec.push_back(s2[0]);
    }
    arr.push_back(std::move(vec));
  }
  for (auto &x: arr) {
    for (auto &c: x) cout << c << ' ';
    cout << '\n';
  }
  cout << "-----------\n";
  Solution solve{};
  auto res = solve.rotateTheBox(arr);
  for (auto &x: res) {
    for (auto &c: x) cout << c << ' ';
    cout << '\n';
  }
  cout << "============\n";
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

