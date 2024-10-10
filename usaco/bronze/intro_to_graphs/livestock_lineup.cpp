#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


constexpr auto max_stream_size = std::numeric_limits<std::streamsize>::max();

ifstream fin("lineup.in");
ofstream fout("lineup.out");

std::array<string, 8> cows{ "Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue" };

// NOTE: few testcases are failing.
// 
// Intuition: permute through sorted set of names, which will give permutations in lexographical order
// with each permutation, match the condition for the chain
void solve() {
  ll n;
  fin >> n;
  fin.ignore(max_stream_size, '\n');
  sort(cows.begin(), cows.end());

  unordered_map<string, vector<string>> adj;
  while (n--) {
    string s;
    getline(fin, s, '\n');
    ll fspace=s.find_first_of(" "), lspace=s.find_last_of(" ");
    string fname=s.substr(0, fspace), lname=s.substr(lspace+1, s.size()-lspace-1);
    adj[fname].push_back(lname);

    // more test case are passing if I'm not making this (and below logic
    // accordingly) two ways
    // adj[lname].push_back(fname);
  }

  for (auto &[key, value]: adj) {
    cout << key << ": ";
    for (auto &val: value) cout << val << ' ';
    cout << '\n';
  }

  do {
    bool found=true;
    for (ll i=0; i<8; i++) {
      if (adj.find(cows[i])!=adj.end()) {
        if (!((i!=0&&cows[i-1]==adj[cows[i]][0])
          || (i<7&&cows[i+1]==adj[cows[i]][0]))) {
          found=false;
        }
      }
    }
    if (found) {
      for (auto &cow: cows) {
        fout << cow << '\n';
      }
      break;
    }
  } while (next_permutation(cows.begin(), cows.end()));
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}

