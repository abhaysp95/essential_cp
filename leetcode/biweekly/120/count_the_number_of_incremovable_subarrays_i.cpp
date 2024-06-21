#include <vector>
#include <list>

using namespace std;

class Solution {
    public:
        // my solution during contest
        int incremovableSubarrayCount(vector<int>& nums) {
            int n = (int)nums.size();

            list<int> l{};

            int count = 0;

            for (int i = 0; i < n; i++) {
                l.clear();
                l.insert(l.end(), nums.begin(), nums.end());
                for (int j = i; j < n; j++) {
                    list<int>::iterator iterb = l.begin();
                    list<int>::iterator itere = l.begin();
                    advance(iterb, i);
                    advance(itere, i + 1);
                    l.erase(iterb, itere);
                    vector<int> vec{};
                    vec.insert(vec.end(), l.begin(), l.end());
                    // for (const int x: vec)  cout << x << ' ';
                    // cout << '\n';
                    if (vec.size() == 1) count++;
                    else {
                        bool inc = true;
                        for (int k = 1; k < (int)vec.size(); k++) {
                            if (vec[k - 1] >= vec[k]) {
                                inc = false;
                                break;
                            }
                        }
                        if (inc) count++;
                    }
                }
            }       return count;
        }

        // better solution
        int incremovableSubarrayCount_another(vector<int>& nums) {
            int count = 0;
            int n = (int)nums.size();
            for (int l = 0; l < n; l++) {
                for (int r = l; r < n; r++) {
                    bool inc = true;
                    for (int k = 0; k < l; k++) {
                        if (k != 0 && nums[k - 1] >= nums[k]) {
                            inc = false;
                            break;
                        }
                    }
                    // since the array will be divided in two parts, we need to
                    // check if last element of first part is smaller than first
                    // element of other part also
                    if (inc && l > 0 && r + 1 < n && nums[l - 1] >= nums[r + 1]) inc = false;
                    if (inc) {
                        for (int k = r + 1; k < n; k++) {
                            if (k + 1 < n && nums[k] >= nums[k + 1]) {
                                inc = false;
                                break;
                            }
                        }
                    }
                    if (inc) count++;
                }
            }

            return count;
        }
};
