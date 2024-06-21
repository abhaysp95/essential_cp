#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

inline int nxt(istream& cin = std::cin) {
	int x;
	cin >> x;
	return x;
}

struct Node {
    int sts = 1; // subtree size
    vector<int> pos;
    vector<int> neg;

    Node(int cost) {
        if (cost > 0) pos.push_back(cost);
        else neg.push_back(cost);
    }

    void updateNode(const Node& node) {
        sts += node.sts;
        pos.insert(pos.end(), all(node.pos));
        neg.insert(neg.end(), all(node.neg));

        sort(all(pos), greater<>());
        sort(all(neg));

        if (pos.size() > 3) pos.erase(pos.begin() + 3);
        if (neg.size() > 3) neg.erase(neg.begin() + 2);
    }

    ll populate() {
        if (sts < 3) return 1;
        ll ans = 0;

        if (pos.size() == 3) {
            ans = pos[0] * pos[1] * pos[2];
        }
        if (neg.size() == 2 && !pos.empty()) {
            ans = max(ans, 1LL * neg[0] * neg[1] * pos[pos.size() - 1]);
        }

        return ans;
    }
};

class Solution {
    public:
        vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
            vector<vector<int>> adj(cost.size());
            vector<ll> ans(cost.size());

            for (auto x: edges) {
                adj[x[0]].push_back(x[1]);
                adj[x[1]].push_back(x[0]);
            }

            vector<ll> posc, negc;

            function<Node(int, int)> dfs = [&](int node, int parent) -> Node {
                Node cnode(cost[node]);

                for (int x: adj[node]) {
                    if (x == parent) continue;
                    Node child = dfs(x, node);
                    cnode.updateNode(child);
                }

                ans[node] = cnode.populate();

                return cnode;
            };

            dfs(0, -1);

            return ans;
        }
};
