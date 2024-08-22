// https://atcoder.jp/contests/abc045/tasks/arc061_a?lang=en

#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

ll make_num(string& s, vector<bool>& op) {
  if (s.size()-1!=op.size()) throw logic_error("s & op size different");
  ll sum=0;
  ll n=s[0]-'0';
  for (int i=1;i<s.size();i++) {
    if (!op[i-1]) n=n*10+(s[i]-'0');
    else {
      sum+=n;
      n=s[i]-'0';
    }
  }
  sum+=n;
  return sum;
}

void solve() {
  string s;
  cin >> s;
  int sz=s.size();

  ll sum=0;
  for (int mask=0;mask<(1<<(sz-1));mask++) {
    vector<bool> op(sz-1, false);
    for (int i=0;i<sz-1;i++) {
      if (mask&(1<<i)) op[i]=true;
    }
    cout << '\n';
    sum+=make_num(s, op);
  }

  cout << sum << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}

