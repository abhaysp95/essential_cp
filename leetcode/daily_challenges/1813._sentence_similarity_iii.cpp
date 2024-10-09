#include <algorithm>
#include <bits/stdc++.h>
#include <string>

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
  auto get_words(string_view sentence) -> vector<string> {
    ll from=0;
    vector<string> words{};
    while (from<sentence.size()) {
      if (auto idx=sentence.find_first_of(" ", from); idx != string::npos) {
        words.push_back(string( sentence.substr(from, idx-from)));
        from=idx+1;
      } else {
        words.push_back(string( sentence.substr(from, sentence.size()-from)));
        break;
      }
    }
    return words;
  }
  auto are_similar(const vector<string>& big, const vector<string>& small) -> bool {
    // 1. smaller one should be prefix
    // 2. smaller one should be suffix
    // 3. one substring could be inserted to smaller one in between one time to
    // make it similar

    /* No need for this */
    // if (big.size()==small.size()) {
    //   for (auto i=0; i<small.size(); i++) {
    //     if (big.at(i)!=small.at(i)) return false;
    //   }
    //   return true;
    // }

    auto ibegin=small.begin(),iend=small.end()-1;
    for (auto iter=big.begin(); ibegin!=small.end() && *ibegin==*iter && iter!=big.end(); ibegin++,iter++) {}
    if (ibegin>iend) return true;
    for (auto iter=big.rbegin(); iend!=small.begin()-1 && *iend==*iter && iter!=big.rend(); iend--,iter++) {}
    if (ibegin>iend) return true;
    return false;
  }
public:
  bool areSentencesSimilar(string sentence1, string sentence2) {
    auto wone = get_words(sentence1), wtwo = get_words(sentence2);
    for (auto w: wone) {
      cout << w << ' ';
    }
    cout << '\n';
    for (auto w: wtwo) {
      cout << w << ' ';
    }
    cout << '\n';
    return wone.size()>wtwo.size() ? are_similar(wone, wtwo) : are_similar(wtwo, wone);
  }
};

void solve() {
  string s1, s2;
  getline(cin, s1, '\n');
  getline(cin, s2, '\n');
  dbg(s1), dbg(s2);
  Solution solve;
  cout << solve.areSentencesSimilar(s1, s2) << endl;
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

