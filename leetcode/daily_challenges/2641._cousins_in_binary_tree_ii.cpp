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

// solution is O(Nxln(ln(N))) time complexity (close to linear),
// but is heavy on space. Retry again with reduced space.
// As the solution might fail for N=1e5, where space is restricted to 1<<8 MB
class Solution {
  using ll = long long;
  void update_nodes(const vector<pair<TreeNode*, TreeNode*>>& nodes) {
    ll level_sum = 0;
    for (auto &node: nodes) {
      cout << node.first->val << ' ';
      level_sum += node.first->val;
    }
    cout << '\n';
    cout << "level_sum: " << level_sum << '\n';
    vector<ll> new_vals(nodes.size(), 0);
    for (ll i=0; i<nodes.size(); i++) {
      auto [child, parent] = nodes[i];
      ll sibling_sum=child->val;
      if (child==parent->left && parent->right!=nullptr) {
        sibling_sum += parent->right->val;
      } else if (child==parent->right && parent->left!=nullptr) {
        sibling_sum += parent->left->val;
      }
      new_vals[i] = level_sum - sibling_sum;
      cout << "sibling sum: " << sibling_sum << ", new val: " << new_vals[i] << '\n';
    }
    ll i=0;
    for (auto &[node, parent]: nodes) {
      node->val = new_vals[i++];
      cout << node->val << ' ';
    }
    cout << "\n------\n";
  }
public:
  TreeNode* replaceValueInTree(TreeNode* root) {
    queue<pair<TreeNode*, ll>> q;
    q.push({root, 0});
    ll gl=-1;
    vector<pair<TreeNode*, TreeNode*>> nodes;
    while (!q.empty()) {
      auto [cn, cl] = q.front();
      q.pop();
      if (gl != cl) {
        // do operations here
        update_nodes(nodes);
        nodes.clear();
        gl = cl;
      }
      if (cn->left!=nullptr) {
        q.push({cn->left, cl+1});
        nodes.push_back({cn->left, cn});
      }
      if (cn->right!=nullptr) {
        q.push({cn->right, cl+1});
        nodes.push_back({cn->right, cn});
      }
    }
    root->val = 0; 
    return root;
  }
};

#define ll long long

TreeNode* make_binary_tree(const vector<string>& nodes) {
  if (nodes[0]=="null") return nullptr;
  TreeNode* root = new TreeNode(stoll(nodes[0]));
  queue<pair<TreeNode*, ll>> q;
  q.push({root, 0});
  while (!q.empty()) {
    auto &[cn, ci] = q.front();
    q.pop();
    if (ll i=2*ci+1; i<nodes.size() && nodes[i]!="null") {
      cn->left=new TreeNode(stoll(nodes[i]));
      q.push({cn->left,i});
    }
    if (ll i=2*ci+2; i<nodes.size() && nodes[i]!="null") {
      cn->right=new TreeNode(stoll(nodes[i]));
      q.push({cn->right,i});
    }
  }

  return root;
}

void level_order_traversal_binary(TreeNode* root) {
  queue<TreeNode*> q;
  q.push(root);
  while (!q.empty()) {
    auto &cn = q.front();
    q.pop();
    if (cn==nullptr) {
      cout << "null ";
    } else {
      cout << cn->val << " ";
      q.push(cn->left);
      q.push(cn->right);
    }
  }
  cout << endl;
}

void solve() {
	// type here
  vector<string> vs;
  string input;
  cin >> input;
  input = input.substr(1, input.size()-2);
  cout << input << '\n';
  stringstream ss{input};
  string s;
  while (getline(ss, s, ',')) {
    if (!s.empty()) vs.push_back(s);
  }
  for (auto &x: vs) cout << x << '\n';
  TreeNode* root = make_binary_tree(vs);
  level_order_traversal_binary(root);
  Solution solve{};
  level_order_traversal_binary(solve.replaceValueInTree(root));
}

int32_t main(void) {
	FAST_IO;

	// int T = nxt();
	// while (T--) {
		solve();
	// }

	return 0;
}

