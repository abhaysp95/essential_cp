// https://codeforces.com/problemset/problem/263/A

#include <cstdlib>
#include <vector>
#include <iostream>
using namespace std;

int main(void) {
  vector<vector<int>> mat(5, vector<int>(5, 0));

  int sx = 0, sy = 0;
  for (size_t i = 0; i < 5; i++) {
    for (size_t j = 0; j < 5; j++) {
      cin >> mat[i][j];
      if (mat[i][j] == 1) {
        sx = i, sy = j;
      }
    }
  }

  cout << abs(sx - 2) + abs(sy - 2) << endl;
  return 0;
}
