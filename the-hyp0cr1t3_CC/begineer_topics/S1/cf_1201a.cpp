// https://codeforces.com/problemset/problem/1201/A

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
  int n = 0, m = 0;
  cin >> n >> m;

  vector<string> ans(n);
  for (size_t i = 0; i < n; i++) {
    cin >> ans[i];
  }

  vector<int> scores(m);
  for (size_t i = 0; i < m; i++) {
    cin >> scores[i];
  }

  size_t score = 0;
  for (size_t i = 0; i < m; i++) {
    vector<int> freq(26, 0);
    int mf = -1e9;
    for (size_t j = 0; j < n; j++) {
      size_t idx = ans[j][i] - 'A';
      freq[idx] += 1;
      mf = max(mf, freq[idx]);
    }
    score += (mf * scores[i]);
  }

  cout << score << endl;

  return 0;
}
