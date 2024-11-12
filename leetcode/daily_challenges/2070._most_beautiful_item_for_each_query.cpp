#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
// #define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

// time-complexity: O(NlogN + MlogN)
class Solution {
  using ll = long long;
public:
  ll get_beauty(vector<vector<int>>& items, int q) {
    auto pos = upper_bound(items.begin(), items.end(), vector{q, 0},
                           [](const vector<int>& a, const vector<int>& b) {
                             return a[0] < b[0];
                           });
    auto idx=distance(items.begin(), pos);
    if (pos==items.end()) return items[idx-1][1];
    if (idx==0) return 0;
    else return items[idx-1][1];
  }
  vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
    sort(items.begin(), items.end(), [](const vector<int>& item1, const vector<int>& item2) {
      return item1[0]==item2[0] ? item1[1] < item2[1] : item1[0] < item2[0];
    });
    // since, we need to get maximum beauty for prices lte to queries[i], we'll
    // update the price with the maximum up till i, so that items[i][1] will
    // have always have gte price for <=i index
    ll mp=items[0][1];
    for (ll i=1; i<items.size(); i++) {
      if (mp<items[i][1]) {
        mp=items[i][1];
      } 
      items[i][1]=mp;
    }
    vector<int> res{};
    for (auto &q: queries) {
      res.push_back(get_beauty(items, q));
    }
    return res;
  }
};

#define ll long long

void solve() {
  string input;
  cin >> input;
  input = input.substr(1, input.size()-1);
  istringstream istream{input};
  vector<vector<int>> arr;
  for (string s; getline(istream, s, ']');) {
    if (s.empty()) continue;
    if (s[0]=='[') s=s.substr(1,s.size()-1);
    else if (s[0]==',') s=s.substr(2,s.size()-2);
    ll idx=s.find(",");
    int a=stoi(s.substr(0, idx));
    int b=stoi(s.substr(idx+1,s.size()-idx-1));
    arr.push_back(vector<int>{a,b});
  }
  cin >> input;
  input = input.substr(1, input.size()-1);
  vector<int> q{};
  istringstream qstream{input};
  for (string s; getline(qstream, s, ',');) {
    if (s.empty()) continue;
    q.push_back(stoi(s));
  }
  for (auto &x: q) cout << x << ' ';
  cout << '\n';
  Solution solve{};
  auto res = solve.maximumBeauty(arr, q);
  for (auto &x: res) {
    cout << x << ' ';
  }
  cout << '\n';
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

