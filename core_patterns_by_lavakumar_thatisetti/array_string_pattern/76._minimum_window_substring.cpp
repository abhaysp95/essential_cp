#include <bits/stdc++.h>

using namespace std;

class Solution {
  bool shast(unordered_map<char, int> &sf, unordered_map<char, int> &tf) {
    for (auto &p : tf) {
      if (sf[p.first] < p.second)
        return false;
    }
    return true;
  }

public:
  string minWindow(string s, string t) {
    unordered_map<char, int> sf{}, tf{};
    for (const char c : t)
      tf[c]++;
    int has = tf.size();
    int need = 0; // in sense, if need is 0, it needs all the has
    int i = 0, j = 0, n = s.size();
    int ri = 0, rj = -1;
    while (j < n) {
      sf[s[j]]++; // can be slightly speed optimized as in, if tf don't have,
                  // don't add it, but then keep the below check inside the
                  // if (tf[s[j]]) {...} block too
      if (sf[s[j]] == tf[s[j]])
        need++;

      while (has == need) {
        if (rj == -1 || rj - ri + 1 > j - i + 1) {
          ri = i, rj = j;
          cout << format("Updating, ri: {}, rj: {}, s: {}\n", ri, rj,
                         s.substr(ri, rj - ri + 1));
        }
        sf[s[i]]--;
        if (sf[s[i]] < tf[s[i]])
          need--;
        i++;
      }
      j++;
    }

    return s.substr(ri, rj - ri + 1);
  }

  string minWindowFirst(string s, string t) {
    unordered_map<char, int> sf{}, tf{};
    int ri = 0, rj = -1;
    for (const char p : t) {
      tf[p]++;
    }
    int i = 0, j = 0, n = s.size();
    auto shast = [&]() -> bool {
      for (auto &p : tf) {
        if (sf[p.first] < p.second)
          return false;
      }
      return true;
    };
    while (j < n) {
      sf[s[j]]++;
      while (shast()) {
        sf[s[i++]]--;
      }
      if (rj == -1 || (rj - ri + 1 > j - i + 1)) {
        ri = i, rj = j;
      }
      j++;
    }

    return s.substr(ri, rj - ri + 1);
  }
};

int main(void) {
  int T = 0;
  cin >> T;
  Solution solve{};
  while (T--) {
    string s{}, t{};
    cout << s << " " << t << '\n';
    cin >> s >> t;
    cout << solve.minWindow(s, t) << endl;
  }
}
