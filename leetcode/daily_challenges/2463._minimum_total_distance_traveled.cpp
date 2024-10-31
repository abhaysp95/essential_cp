#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
// #define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

// greedy solution fails
class Solution {
  using ll = long long;
  #define LOWER -1e9;
  #define UPPER -1e9;
public:
  long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
    ll tot=0;
    sort(factory.begin(), factory.end(), [](vector<int>& a, vector<int>& b) {
      return a[0] < b[0] ? a[0] : (a[0] > b[0] ? b[0] : (a[1] > b[1] ? a[1] : b[1]));
    });
    ll lf=factory[0][0],rf=factory[factory.size()-1][0];
    for (ll i=0; i<robot.size(); i++) {
      ll pidx=-1,cdist=1e9;
      for (ll j=0; j<factory.size(); j++) {
        if ((abs(robot[i]-factory[j][0]) < cdist) && (factory[j][1]>0)) {
          cdist=abs(robot[i]-factory[j][0]);
          factory[j][1]-=1;
          if (pidx!=-1) factory[pidx][1]+=1;  // resetting
          pidx=j;
        }
      }
      tot+=cdist;
    }
    return tot;
  }
};

void solve() {
	// type here
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

