#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
    public:
        vector<int> findMissingAndRepeatedValues1(vector<vector<int>>& grid) {
            unordered_map<int, int> umap{};

            int n = grid.size();
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    umap[grid[i][j]]++;
                }
            }

            int dup = -1, missing = -1;
            for (int i = 1; i <= n*n; i++) {
                if (umap.find(i) == umap.end()) missing = i;
                if (umap[i] == 2) dup = i;
            }

            return vector<int>{dup, missing};
        }

        vector<int> findMissingAndRepeatedValues2(vector<vector<int>>& grid) {
            vector<int> arr{};

            for (vector<vector<int>>::iterator iter = grid.begin(); iter != grid.end(); iter++) {
                arr.insert(arr.end(), iter->begin(), iter->end());
            }

            int i = 0, dup = -1, missing = -1;
            while (i < arr.size()) {
                if (arr[i] != arr[arr[i] - 1]) swap(arr[i], arr[arr[i] - 1]);
                else i++;
            }

            for (int i = 0; i < arr.size(); i++) {
                if (arr[i] != i + 1) missing = i + 1, dup = arr[i];
            }

            return vector<int>{dup, missing};
        }

        // or we can use vector with it's index denoting the number and value denoting frequency just like first approach
};

int main(void) {}
