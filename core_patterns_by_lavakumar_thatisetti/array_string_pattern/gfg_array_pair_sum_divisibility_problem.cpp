#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  bool canPair(vector<int> &arr, int k) {
    int n = (int)arr.size();
    if (n & 1) {
      return false;
    }
    unordered_map<int, int> umap{};
    for (int i=0; i<n; i++) {
      int r = arr[i] % k;
      if (umap.find(k - r) != umap.end()) {
        umap[k-r]--;
        if (umap[k-r] == 0) umap.erase(k-r);
      } else {
        umap[r]++;
      }
    }
    if (umap.empty() 
      || (umap.size() == 1 && umap.find(0) != umap.end())) {
      return true;
    }
    return false;
  }
};
