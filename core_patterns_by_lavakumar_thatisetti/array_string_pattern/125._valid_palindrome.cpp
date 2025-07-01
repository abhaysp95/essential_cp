#include <bits/stdc++.h>
#include <lc_list.hpp>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    int n=s.size(), l=0, r=n-1;
    while (l < r) {
      while (l < r && !isalnum(s[l])) l++;
      while (l < r && !isalnum(s[r])) r--;
      if (tolower(s[l]) != tolower(s[r])) return false;
      l++, r--;
    }
    return true;
  }
};

int main() {
  Solution solve;
  int T=0;
  cin >> T;
  cin.ignore();
  while (T--) {
    string s{};
    getline(cin, s);
    cout << (solve.isPalindrome(s) ? "true" : "false") << '\n';
  }
  cout << endl;
}
