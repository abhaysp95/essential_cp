#include <bits/stdc++.h>

using namespace std;

class Solution {

public:
  int maxVowels(string s, int k) {
    int res = 0, cvow = 0, n = s.size();
    int i = 0, j = 0;
    bitset<26> vowel;
    vowel['a' - 'a'] = 1;
    vowel['e' - 'a'] = 1;
    vowel['i' - 'a'] = 1;
    vowel['o' - 'a'] = 1;
    vowel['u' - 'a'] = 1;
    while (j < k) {
      if (vowel[s[j++] - 'a']) {
        cvow++;
      }
    }
    while (j < n) {
      res = max(res, cvow);
      if (vowel[s[i++] - 'a']) {
        cvow--;
      }
      if (vowel[s[j++] - 'a']) {
        cvow++;
      }
    }
    res = max(res, cvow);
    return res;
  }
};
