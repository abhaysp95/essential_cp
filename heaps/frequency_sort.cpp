#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// Print the elements of an array in the increasing frequency if 2 numbers have
// same frequency then print the one which came first.

int main(void) {
    vector<int> vec{5, 2, 2, 8, 5, 6, 8, 8};

    unordered_map<int, int> umap;
    for (const int x: vec) umap[x]++;

    vector<pair<int, int>> freq{};
    for (const pair<const int, int>& p: umap) {
        freq.push_back({p.second, p.first});
    }

    sort(freq.begin(), freq.end());

    for (const pair<int, int>& p: freq) {
        cout << p.second << ' ';
    }
    cout << endl;

    return 0;
}
