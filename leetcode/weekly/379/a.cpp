#include <iostream>
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

class Solution {
    public:
        int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
            vector<pair<int, int>> val(sz(dimensions));

            for (int i = 0; i < sz(dimensions); i++) {
                val[i].first = dimensions[i][0] * dimensions[i][0] + dimensions[i][1] * dimensions[i][1];
                val[i].second = dimensions[i][0] * dimensions[i][1];
            }

            sort(all(val), [&](pair<int, int>& p1, pair<int, int>& p2) {
                    if (p1.first > p2.first) return true;
                    if (p1.first == p2.first) return p1.second > p2.second;
                    return false;
                    });

            return val[0].second;
        }
};
