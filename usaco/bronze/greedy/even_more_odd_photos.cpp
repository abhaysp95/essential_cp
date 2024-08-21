#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");


void solve() {
  int n;
  cin >> n;
  vector<int> even, odd;
  for (int i=0; i<n; i++) {
    int t;
    cin >> t;
    if (t&1) odd.push_back(t);
    else even.push_back(t);
  }
  int oz=odd.size(),ez=even.size();

  int g=0;
  if (oz>ez) {
    if ((oz-ez)%3==1) oz-=2;
  }
  if (oz==ez) {
    g=oz*2;
  } else if (ez>oz) {
    g=2*oz+1;
  } else {
    int diff=oz-ez;
    g=ez*2;
    if (diff/3>0) {
      g+=((diff/3)*2);
    }
    int rem=diff%3;
    if (rem==2) {
      g++;
    } else {
      // shouldn't reach here
      // g--;  // in odd, instead of using 1, using 3 odds to make it one
      // odd group
      // already used this logic in ln.20
      // my guess that this here didn't work because when we make 3 odd
      // to 1, it's possible that oz becomes less than ez and so
      // confirming and changing this beforehand is the correct way
    }
  }

  cout << g << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve();

	return 0;
}

