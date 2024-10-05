#include <bits/stdc++.h>

using namespace std;


class Solution {
using ll = long long;
public:
  bool perm_exists(std::array<ll, 26> sub_freq, const string_view& sub, const string_view& sup, ll idx) {
    if (idx+sub.size()>sup.size()) {
      return false;
    }
    for (ll j=0; j<sub.size(); j++) {
      ll i=idx+j;
      if (sub_freq[sup[i]-'a']==0) {
        return false;
      }
      sub_freq[sup[i]-'a']--;
    }
    return true;
  }

  bool checkInclusion(string s1, string s2) {
    std::array<ll, 26> sub_freq{};
    for (ll i=0; i<s1.size(); i++) {
      sub_freq[s1[i]-'a']++;
    }
    for (ll i=0;i<s2.size(); i++) {
      if (perm_exists(sub_freq, s1, s2, i)) {
        return true;
      }
    }
    return false;
  }
};

int main(void) {
  Solution solve{};
  string s1, s2;
  cin >> s1 >> s2;
  cout << solve.checkInclusion(s1, s2) << endl;
}
