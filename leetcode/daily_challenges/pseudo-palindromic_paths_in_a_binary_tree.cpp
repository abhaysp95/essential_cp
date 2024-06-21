#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <list>
#include <cmath>
#include <string>
#include <cstring>
#include <iterator>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define INF (int)1e9

#define sz(a) (int)(a.size())
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define FAST_IO 	ios_base::sync_with_stdio(false), cin.tie(nullptr), cerr.tie(nullptr)
#define dbg(v) 	cout << "Line(" << __LINE__ << ") -> " << #v << " = " << (v) << endl


ifstream fin("");
ofstream fout("");

inline ll nxt(istream& cin = std::cin) {
	ll x;
	cin >> x;
	return x;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


class Solution {
    public:
        int pseudoPalindromicPaths (TreeNode* root) {
            if (root == nullptr) return 0;

            vector<ll> vec(10, 0);
            return max_path(root, vec, 1);
        }

        ll max_path(TreeNode* root, vector<ll>& vec, ll count) {
            ll ppc = 0;
            vec[root->val - 1]++;

            // if it's leaf node
            if (root->left == nullptr && root->right == nullptr) {
                ppc = -1;
                if (count & 1) {  // odd
                    bool odd_found = false;
                    for (ll i = 0; i < 10; i++) {
                        if ((vec[i] & 1) && !odd_found) {
                            odd_found = true;
                        } else if (vec[i] & 1) ppc = 0;
                    }
                } else {
                    for (ll i = 0; i < 10; i++) {
                        if (vec[i] & 1) ppc = 0;
                    }
                }

                vec[root->val - 1]--;
                return ppc == -1 ? 1 : 0;
            }

            if (root->left != nullptr) ppc += max_path(root->left, vec, count + 1);
            if (root->right != nullptr) ppc += max_path(root->right, vec, count + 1);
            vec[root->val - 1]--;

            return ppc;
        }
};

void verify(TreeNode* root) {
    queue<TreeNode*> q{};
    q.push(root);

    while (!q.empty()) {
        auto node = q.front();
        q.pop();

        cout << node->val << " ";
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
}

void solve() {
    string input;
    cin >> input;
    input = input.substr(1, sz(input) - 2);

    int n;  // read here
    vector<string> vec;

    string token;
    stringstream istream(input);
    while (getline(istream, token, ',')) {
        if (token == "") continue;
        vec.push_back(token);
    }

    n = sz(vec);

    TreeNode* root = new TreeNode(stoi(vec[0]));
    queue<pair<TreeNode*, ll>> q{};
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, l] = q.front();
        q.pop();

        if (2 * l + 1 <= n - 1 && vec[2 * l + 1] != "null") {
            node->left = new TreeNode(stoi(vec[2 * l + 1]));
            q.push({node->left, 2 * l + 1});
        } else node->left = nullptr;
        if (2 * l + 2 <= n - 1 && vec[2 * l + 2] != "null") {
            node->right = new TreeNode(stoi(vec[2 * l + 2]));
            q.push({node->right, 2 * l + 2});
        } else node->right = nullptr;
    }

    // verify(root);

    Solution solve{};
    cout << solve.pseudoPalindromicPaths(root) << '\n';
}

int32_t main(void) {
	FAST_IO;

	int T = 1;
	while (T--) {
		solve();
	}

	return 0;
}

