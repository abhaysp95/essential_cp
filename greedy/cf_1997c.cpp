// https://codeforces.com/contest/1997/problem/C

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
  int t = 0;
  cin >> t;

  while (t--) {
    int n = 0;
    cin >> n;

    string s;
    cin >> s;

    stack<int> ob, ep;
    int sum = 0;
    bool bad = false;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '_') {
        if (ob.size() > 0)  {
          sum += (i + 1) - ob.top();
          ob.pop();
        } else ep.push(i + 1);
      }
      if (s[i] == '(')
        ob.push(i + 1);
      if (s[i] == ')') {
        if (ep.size() > 0) {
          sum += (i + 1) - ep.top();
          ep.pop();
        } else {
          bad = true;
          break;
        }
      }
    }

    if (bad) {
      cout << -1 << '\n';
    } else {
      cout << sum << '\n';
    }

  }
  return 0;
}

// NOTE: This is greedy solution.
// It is greedy because, the question says to place the brackets so that we get
// minimum sum when we make RBS.
// And so, as soon as we see '(' we know that the next empty place should have a ')' for it.
// and if we see, '_', we use it, such that if we have any ( before, this place would get ) else we continue to keep it
// and if we get ), we know that there should be an empty place before itself, as close as it can be.
// and thus, stack is perfect for this use, where we want to get the closest place before _ or )
