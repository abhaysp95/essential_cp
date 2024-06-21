#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/* Given an unsorted array and two numbers x and k, find k closest values to x.
Input : arr[] = {10, 2, 14, 4, 7, 6}, x = 5, k = 3  */

using pii = pair<int, int>;

struct _comparator {
    bool operator()(pii& l, pii& r) {
        return l.first < r.first; // similar to less<T>
    }
};

int main(void) {
    vector<int> vec{10, 2, 14, 4, 7, 6};
    int x = 5, k = 3;
    priority_queue<pii, vector<pii>, _comparator> heap; // max heap; pair<int, int> = {diff, num}

    // NOTE: we can just use priority_queue<pair<int, int>> where pair<int, int>
    // is {diff, num} as this max heap will sort the pair based on the .first,
    // or same is true for pair<int, vector<int>> or anything. It'll compare
    // based on key, value can be anything

    // O(nlogk)
    for (const int n: vec) {
        heap.push({abs(n - x), n});
        if (heap.size() > k) heap.pop();
    }

    while (!heap.empty()) {
        cout << heap.top().second << '\n';
        heap.pop();
    }

    return 0;
}

// if using this approach change _comparator to (l.first > r.fist)
// O(nlogn)
    /* for (const int num: vec) {
        heap.push({abs(num - x), num});
    }

    for (int i = 0; i < k; i++) {
        cout << heap.top().second << '\n';
        heap.pop();
    } */
