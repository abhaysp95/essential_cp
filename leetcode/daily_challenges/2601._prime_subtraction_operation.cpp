#include <bits/stdc++.h>

using namespace std;

#define uint unsigned int
// #define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

// NOTE: solution follows the greedy approach.
// Fill the max prime no. for a number i, which is less than i.
// For a given num i, start by subtracting primes[i] which is a prime less than i and store it.
// then for next number, do the same but also check that diff is bigger than new prev. num.
// Keep doing the same till end
class Solution {
  using ll = long long;
  vector<ll> primes;
public:
  Solution() {
    this->primes.resize(1001);
    fill(this->primes.begin(), this->primes.end(), 1);
    this->primes[0]=0,this->primes[1]=0;
    for (ll i=2; i<1001; i++) {
      if (this->primes[i]) {
        for (ll j=2*i; j<1001; j+=i) this->primes[j]=0;
      }
    }
    ll pp=-1;
    for (ll j=2; j<1001; j++) {
      if (this->primes[j]) {
        pp=j;
      }
      this->primes[j]=pp;
    }
  }
  bool is_strictly_sorted(const vector<int>& nums) {
    for (ll i=1; i<nums.size(); i++) {
      if (nums[i-1]>=nums[i]) return false;
    }
    return true;
  }
  bool primeSubOperation(vector<int>& nums) {
    if (is_strictly_sorted(nums)) return true;
    // do for first element
    for (ll j=nums[0]; j>=2; j--) {
      if (this->primes[j]<nums[0]) {
        nums[0]-=this->primes[j];
        break;
      } 
    }
    if (is_strictly_sorted(nums)) return true;
    // do for rest of the elements
    for (ll i=1; i<nums.size(); i++) {
      for (ll j=nums[i]; j>=2; j--) {
        if (this->primes[j]<nums[i] && nums[i]-this->primes[j]>nums[i-1])  {
          nums[i]-=this->primes[j];
          break;
        }
      }
      if (is_strictly_sorted(nums)) return true;
    }
    return false;
  }
};

void solve() {
  string s;
  cin >> s;
  s = s.substr(1,s.size()-2);
  istringstream istream(s);
  vector<int> nums{};
  for (string in; getline(istream, in, ',');) {
    if (!in.empty()) nums.push_back(stoll(in));
  }
  Solution solve{};
  cout << solve.primeSubOperation(nums) << endl;
}

int32_t main(void) {
  FAST_IO;

	int T;
  cin >> T;
  cin.ignore(1,'\n');
	while (T--) {
		solve();
	}

	return 0;
}

