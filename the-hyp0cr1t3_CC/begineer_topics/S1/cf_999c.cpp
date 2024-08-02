// https://codeforces.com/problemset/problem/999/C

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void print_vec(const vector<T>& vec) {
  for (T x: vec) {
    cout << x << " ";
  }
  cout << "\n";
}

int main(void) {
  int n=0, k=0;
  cin >> n >> k;

  string s;
  cin >> s;

  vector<int> freq(26, 0);
  for (size_t i=0; i<s.size(); i++) {
    freq[s[i]-'a']++;
  }

  vector<int> diff(26, 0);

  int temp_k = k;
  int idx = 0;
  while (temp_k > 0) {
    if (temp_k < freq[idx]) {
      diff[idx] = temp_k;
      temp_k = 0;
    } else {
      diff[idx] = freq[idx];
      temp_k -= freq[idx];
    }
    idx++;
  }

  // std::fill(freq.begin() + idx, freq.end(), 0);

  string res{};
  for (size_t i=0; i<s.size(); i++) {
    if (diff[s[i]-'a'] == 0) {
      res += s[i];
    } else {
      diff[s[i]-'a']--;
    }
  }

  cout << res << endl;

  return 0;
}
