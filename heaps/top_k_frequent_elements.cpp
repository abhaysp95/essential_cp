#include <functional>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

// Given an array of n numbers. Your task is to read numbers from the array and
// keep at-most K numbers at the top (According to their decreasing frequency)
// every time a new number is read.

int main(void) {
    vector<int> arr{5, 2, 1, 3, 2};
    int k = 4;

    unordered_map<int, int> umap{};
    for (const int x: arr) umap[x]++;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> heap{};  // min heap

    int f = 0;
    for (const pair<const int, int>& p: umap) {
        heap.push({p.second, p.first});
        if (f++ >= k) heap.pop();
    }

    while (!heap.empty()) {
        cout << heap.top().second << '\n'; // this will print max frequent in reverse order, ie.,
                                           // small to greatest range
        heap.pop();
    }
    cout << endl;

    return 0;
}
