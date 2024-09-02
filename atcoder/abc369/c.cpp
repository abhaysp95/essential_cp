#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");


// Gives TLE on last 2 test cases
void solve() {
  int n;
  cin >> n;
  vector<int> arr(n,0);
  for (int i=0;i<n;i++)
    cin >> arr[i];

  ll p=0;
  for (int i=0;i<n;i++) {
    int pdiff=0;
    for (int j=i;j<n;j++) {
      if (i==j) p++;
      else if (i+1==j) {
        pdiff=abs(arr[j]-arr[i]);
        p++;
      } else {
        if (abs(arr[j]-arr[j-1])!=pdiff) break;
        p++;
      }
    }
  }
  cout << p << '\n';
}

ll psum(ll a, ll d, ll n) {
  return (n*(2*a+(n-1)*d))/2;
}

// giving WA on some test cases
// the method is correct though I believe some edge case is missing
void solve2() {
  int n;
  cin >> n;
  vector<int> arr(n,0);
  vector<int> parr(n+1,0);
  for (int i=0;i<n;i++) {
    cin >> arr[i];
    parr[i+1]=parr[i]+arr[i];
  }

  ll p=0;
  for (int i=0;i<n;i++) {
    p++;
    if (i+1<=n) {
      int d=arr[i+1]-arr[i];  // d can be -ve also
      if (psum(arr[i+1],d,n-(i+1))==parr[n]-parr[i+1]) p+=n-(i+1);
      else {
        int l=i+1,r=n-1;
        int maxp=1;
        while(l<=r) {
          int mid=l+(r-l)/2;
          if (psum(arr[i+1],d,mid-i)==parr[mid+1]-parr[i+1]) {
            maxp=max(maxp,mid-i);
            l=mid+1;
          } else r=mid-1;
        }
        p+=maxp;
      }
    }
  }
  cout << p << '\n';
}

// this is the solution which is based on editorial
void solve3() {
  ll n;
  cin >> n;
  vector<ll> arr(n,0);
  vector<ll> diff(n-1,0);
  for (ll i=0;i<n;i++) {
    cin >> arr[i];
    if (i>0) diff[i-1]=arr[i]-arr[i-1];
  }

  // NOTE: why didn't just use map(dict) for diff ?
  // Because, we need diff with its count in sequential order
  // Lets say diff is = 14,14,18,19,19,14,20
  // with map it would be (14,3),(18,1),(19,2),(20,1)
  // but for our problem this should be (14,2),(18,1),(19,2),(14,1),(20,1)

  ll p=n;
  if (!diff.empty()) {
    // run length compression
    vector<pair<ll,ll>> comps;
    ll start=diff[0],c=1;
    for (ll i=1;i<n-1;i++) {
      if (diff[i]==start) c++;
      else {
        comps.push_back({start,c});
        start=diff[i];
        c=1;
      }
    }
    comps.push_back({start,c});

    for (auto &comp: comps) {
      ll s=comp.second;
      p+=(s*(s+1))/2;
    }
  }
  cout << p << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve3();

	return 0;
}

