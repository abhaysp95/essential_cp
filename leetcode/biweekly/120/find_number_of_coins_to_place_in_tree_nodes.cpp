#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
        vector<long long> placedCoins(vector<vector<int>>& edges, vector<int>& cost) {
            vector<vector<int>> adj(cost.size());

            for (int i = 0; i < (int)edges.size(); i++) {
                adj[edges[i][0]].push_back(edges[i][1]);
                adj[edges[i][1]].push_back(edges[i][0]);
            }

            vector<long long> res(cost.size());

            queue<pair<int, int>> q{};
            q.push({0, -1});

            while (!q.empty()) {
                pair node = q.front();
                q.pop();

                res[node.first] = cost_subtree_size(adj, cost, node.first);
                if (res[node.first] < 0) res[node.first] = 0;

                for (const int x: adj[node.first]) {
                    if (node.second != x)
                        q.push({x, node.first});
                }
            }

            return res;
        }

        long long cost_subtree_size(const vector<vector<int>>& adj, const vector<int>& cost, int cnode) {
            queue<pair<int, int>> q{};
            priority_queue<int, vector<int>, greater<>> heap{};  // max heap
            priority_queue<int> mheap{};  // min heap
            q.push({cnode, -1});

            int count = 0;
            while (!q.empty()) {
                count++;
                pair node = q.front();
                q.pop();
                if (cost[node.first] >= 0) heap.push(cost[node.first]);
                else mheap.push(cost[node.first]);

                if (heap.size() > 3) {
                    heap.pop();
                }
                if (mheap.size() > 2) mheap.pop();

                for (const int x: adj[node.first]) {
                    if (node.second != x)
                        q.push({x, node.first});
                }
            }

            if (count < 3) return 1;
            long long mul = 1;
            long long maxn = -1;
            long long neg = 1;
            bool found = false;
            vector<int> pos{};
            if (heap.size() == 3) {
                found = true;
                while (!heap.empty()) {
                    maxn = max(maxn, (long long)heap.top());
                    mul *= heap.top();
                    pos.push_back(heap.top());
                    heap.pop();
                }
            }
            if (mheap.size() == 2 && (!pos.empty() || !heap.empty())) {
                found = true;
                while (!mheap.empty()) {
                    neg *= mheap.top();
                    mheap.pop();
                }
                long long maxn = -1;
                if (!heap.empty()) {
                    while (!heap.empty()) {
                        maxn = max(maxn, (long long)heap.top());
                        heap.pop();
                    }
                } else maxn = pos[2];
                neg *= maxn;
            }
            if (found) return max(mul, neg);

            return 0;
        }
};
