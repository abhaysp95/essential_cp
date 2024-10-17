#include <bits/stdc++.h>

using namespace std;

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("div7.in");
ofstream fout("div7.out");

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

/**
 * Learnings:
 * (a-b)%m = (a%m-b%m)%m
 * Since we have to check for range that if it is divisible by 7, above property
 * can be applied. (a-b), where a>b tells that for index a - index b will give
 * us the sum of the range from prefix summed array
 *
 * If remainder of two numbers for divisor m, is same that means, that sum of
 * the numbers between this range is divisble by m. For example, a remainder is
 * 1 and another is 1, that means, that sum would be multiple of 7 (1 + 7 = 8,
 * which will give 1 as remainder in both case).
 *
 * So, if you find first remainder at index l, and last occurance of same remainder is r, than the range would be (r-l).
 * Note that, range wouldn't be (r-1+1), because we are to only include numbers which when summing are divisble by 7
 */

void solve() {
  ll n;
  fin >> n;
  vector<ll> cows(n, 0);
  for (ll i=0; i<n; i++) fin >> cows[i];
  for (ll i=1; i<n; i++) {
    cows[i]+=cows[i-1];
  }

  ll maxr=0;
  for (ll i=0; i<7; i++) {
    ll l=-1,r=-1;
    for (ll j=0; j<n; j++) {
      if (cows[j]%7==i) {
        if (l==-1) l=j;
        else r=j;
      }
      if (l!=-1 && r!=-1) {
        maxr=max(maxr, r-l);
      }
    }
  }
  fout << maxr << '\n';
}

void solve_brute_force() {
  ll n;
  fin >> n;
  vector<ll> cows(n, 0);
  for (ll i=0; i<n; i++) fin >> cows[i];

  ll maxv=0,maxc=0;
  for (ll i=0; i<n; i++) {
    ll sum=0;
    for (ll j=i; j<n; j++) {
      sum+=cows[j];
      if (sum%7==0 && sum>maxv) {
        maxv = sum;
        maxc=j-i+1;
      }
    }
  }
  fout << maxc << '\n';
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

