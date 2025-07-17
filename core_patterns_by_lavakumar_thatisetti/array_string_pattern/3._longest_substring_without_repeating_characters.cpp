#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0, n = s.size();
    unordered_map<char, int> freq{};
    int res = 0;
    while (j < n) {
      freq[s[j]]++;
      while (freq[s[j]] > 1) {
        freq[s[i++]]--;
      }
      res = max(res, j - i + 1);
      j++;
    }
    return res;
  }

  int lengthOfLongestSubstringFirst(string s) {
    unordered_map<char, int> freq{};
    int i = 0, j = 0, n = s.size();
    auto dup = [&]() -> char {
      for (auto &p : freq) {
        if (p.second > 1) {
          return p.first;
        }
      }
      return -1;
    };
    int res = 0;
    while (j < n) {
      freq[s[j]]++;
      if (char d = dup(); d != -1) {
        while (freq[d] > 1) {
          freq[s[i]]--;
          i++;
        }
      }
      res = max(res, j - i + 1);
      j++;
    }
    return res;
  }
};
