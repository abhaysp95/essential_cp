#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("outofplace.in");
ofstream fout("outofplace.out");

int go_up(vector<int>& place, int x) {
  int c=0,n=place.size();
  for (int i=n-1;i>=0;i--) {
    if (place[x]<place[i]) {
      // dbg(x);
      // dbg(place[x]);
      // dbg(i);
      // dbg(place[i]);
      if (i==n-1) c++;
      else if (place[i]!=place[i+1]) c++;
      // dbg(c);
    }
  }
  return c;
}

int go_down(vector<int>& place, int x) {
  int c=0,n=place.size();
  for (int i=x;i<n;i++) {
    if (place[x]>place[i]) {
      // dbg(x);
      // dbg(place[x]);
      // dbg(i);
      // dbg(place[i]);
      if (i==0) c++;
      else if (place[i]!=place[i-1]) c++;
      // dbg(c);
    }
  }
  return c;
}

// greedy solution
void solve() {
  int n;
  fin >> n;
  vector<int> place(n);
  for (int i=0;i<n;i++)
    fin >> place[i];

  int c=0;
  if (place[0]>place[1]) {
    // dbg("down");
    c=go_down(place, 0);
  } else if (place[n-1]<place[n-2]) {
    // dbg("up");
    c=go_up(place, n-1);
  } else {
    for (int i=1;i<n;i++) {
      if (place[i-1]>place[i]) {
        // dbg("[else] down");
        c=go_down(place,i-1);
        break;
      }
    }
  }

  fout << c << '\n';
}

// non-greedy ad-hoc solution (used sorting)
void solve2() {
  int n;
  fin >> n;
  vector<int> place(n);
  for (int i=0;i<n;i++)
    fin >> place[i];

  vector<int> mp;
  mp.push_back(place[0]);
  for (int i=1;i<n;i++) {
    if (place[i]!=place[i-1]) mp.push_back(place[i]);
  }

  vector<int> mp2(mp);
  sort(mp2.begin(), mp2.end());

  int l=-1,r=-1;
  for (int i=0;i<mp.size();i++) {
    if (mp[i]!=mp2[i]) {
      if (l==-1) l=i;
    }
    if (l!=-1&&mp[i]==mp2[i]) {
      if (r==-1) r=i-1;
    }
  }
  if (l!=-1&&r==-1) r=mp.size()-1;
  fout << r-l << '\n';
}

int32_t main(void) {
  FAST_IO;

		solve2();

	return 0;
}

