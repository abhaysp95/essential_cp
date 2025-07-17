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
