#include <unordered_set>
#include <vector>
#include <unordered_map>

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
        int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
            static vector<int> vec(1e4 + 1, -1);
            static unordered_map<int, int> fa, fb;

            int ac = 0, bc = 0, dc = 0;
            vector<int> didx{};
            for (int i = 0; i < sz(nums1); i++) {
                vec[nums1[i]] = 1;
                fa[nums1[i]]++;
            }

            for (int i = 0; i < sz(nums2); i++) {
                if (vec[nums2[i]] == 1) {
                    dc++;
                    didx.push_back(nums2[i]);
                }
                else vec[nums2[i]] = 2;
                fb[nums2[i]]++;
            }

            for (int i = 0; i < sz(didx); i++) {
                if (ac < sz(nums1) / 2) {
                    ac++;
                    fa[didx[i]]--;
                }
            }

            if (ac < sz(nums1) / 2) {
                for (pair<const int, int>& p: fa) {
                    if (ac >= sz(nums1) / 2) break;
                    if (p.second > 1) {
                        ac += (p.second - 1);
                        p.second = 1;
                    }
                }
            }

            if (ac < sz(nums1) /2 ) {
                for (pair<const int, int>& p: fa) {
                    if (ac >= sz(nums1) / 2) break;
                    ac++;
                    p.second = 0;
                }
            }

            if (bc < sz(nums2) / 2) {
                for (pair<const int, int>& p: fb) {
                    if (bc >= sz(nums2) / 2) break;
                    if (p.second > 1) {
                        bc += (p.second - 1);
                        p.second = 1;
                    }
                }
            }

            if (bc < sz(nums2) /2 ) {
                for (pair<const int, int>& p: fb) {
                    if (bc >= sz(nums2) / 2) break;
                    bc++;
                    p.second = 0;
                }
            }

            unordered_set<int> s;
            for (pair<const int, int>& p: fa) {
                if (p.second != 0) s.insert(p.first);
            }
            for (pair<const int, int>& p: fb) {
                if (p.second != 0) s.insert(p.first);
            }

            return s.size();
    }
};
