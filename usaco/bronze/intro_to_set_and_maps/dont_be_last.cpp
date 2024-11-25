
#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("notlast.in");
ofstream fout("notlast.out");


void solve() {
  ll n;
  fin >> n;
  unordered_map<string, ll> log{};
  fin.ignore();
  for (ll i=0; i<n; i++) {
    string s;
    getline(fin, s);
    ll sidx = s.find(" ");
    string cow = s.substr(0, sidx);
    // cout << s.substr(sidx+1, s.size()-sidx-1) << '\n';
    log[cow]+=stoll(s.substr(sidx+1, s.size()-sidx-1));
  }
  ll mm = 1e9;
  if (log.size()!=7) mm=0;
  else for (auto &[name, amount]: log) mm = min(mm, amount);
  // second min
  string cow="";
  ll sm=1e9;
  for (auto &[name, amount]: log) {
    if (amount>mm && sm>amount) {
      sm=amount;
      cow=name;
    }
  }
  // could be a tie...
  ll c=0;
  for (auto &[name, amount]: log) {
    if (amount==sm) c++;
  }
  fout << (c>1 ? "Tie" : cow) << '\n';
}

int32_t main(void) {
  FAST_IO;

	int T;
  fin >> T;
	while (T--) {
		solve();
	}

	return 0;
}
