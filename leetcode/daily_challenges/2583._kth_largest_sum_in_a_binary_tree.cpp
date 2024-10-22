#include <bits/stdc++.h>
#include <functional>
#include <queue>

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

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
  using ll = long long;
public:
  long long kthLargestLevelSum(TreeNode* root, int k) {
    priority_queue<ll, vector<ll>, greater<>> minheap;
    queue<pair<TreeNode*, ll>> q;
    q.push({root, 0});
    ll gl=0, sum=0;
    while (!q.empty()) {
      auto [cn, cl] = q.front();
      q.pop();
      if (cl==gl) {
        sum+=cn->val;
      } else {
        gl=cl;
        minheap.push(sum);
        if (minheap.size() > k) {
          minheap.pop();
        }
        cout << minheap.top() << '\n';
        sum=cn->val;
      }
      if (cn->left!=nullptr) q.push({cn->left, cl+1});
      if (cn->right!=nullptr) q.push({cn->right, cl+1});
    }
    minheap.push(sum);
    if (minheap.size() > k) minheap.pop();
    return minheap.size() == k ? minheap.top() : -1;
  }
};

void solve() {
  /** Using minheap */
  // ll k = 3;
  // priority_queue<ll, vector<ll>, greater<>> minheap;
  // array<ll, 5> arr{5, 3, 1, 8, 4};
  // 5,3,1,3,4
  //
  // for (ll i=0; i<5; i++) {
  //   if (minheap.size() == 3) {
  //     minheap.pop();
  //   }
  //   minheap.push(arr[i]);
  //   cout << minheap.top() << '\n';
  // }
  // while (!minheap.empty()) cout << minheap.top() << ' ', minheap.pop();
  // cout << endl;
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

