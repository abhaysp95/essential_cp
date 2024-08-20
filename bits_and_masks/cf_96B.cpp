// https://codeforces.com/problemset/problem/96/B
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define ll long long

ll make_num(vector<int>& num) {
  ll n=0;
  int sz=num.size();
  for (int i=sz-1; i>=0; i--) {
    n=n*10+(num[i]==0?4:num[i]);
  }
  return n;
}

ll finding_upper_num(int n, int sz) {
  ll mnum=(ll)1e10; // since upperlimit of n is 1e9, the num can be 4444477777, thus num needs to be greater than this
  for (int mask=0; mask<(1<<sz); mask++) {
    int c4=0,c7=0;
    vector<int> num_arr(sz, 0);
    for (int i=0; i<sz; i++) {
      if (mask&(1<<i)) num_arr[i]=7,c7++;
      else num_arr[i]=4,c4++;
    }
    for (int i=0; i<sz; i++) {
      if (num_arr[i]==0) c4++;
    }
    ll num=make_num(num_arr);
    if (num>=n && c4==c7) {
      mnum=min(mnum,num);
    }
  }

  return mnum;
}

int main(void) {
  ll n;
  scanf("%lld", &n);


  int sz=log10(n)+1;

  // just a shortcut, though this will prevent time in some cases, it's not necessary
  // if (!(sz&1)) { 
  //   int c4=0,c7=0;
  //   ll temp=n;
  //   while(temp) {
  //     int res=temp%10;
  //     if (res!=4&&res!=7) break;
  //     if (temp%10==4) c4++;
  //     else c7++;
  //     temp/=10;
  //   }
  //   if (c4==c7&&c4!=0) {
  //     printf("%lld\n", n);
  //     return 0;
  //   }
  // }

  ll mnum;
  if (sz&1) {
    mnum = finding_upper_num(n, sz+1);
  } else {
    mnum = finding_upper_num(n, sz);
    if (mnum==(ll)1e10) {
      mnum = finding_upper_num(n, sz+2);
    }
  }

  printf("%lld\n", mnum);

  return 0;
}
