#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Given a list of points on the 2-D plane and an integer K. The task is to find
// K closest points to the origin and print them.


int main(void) {
    vector<pair<int, int>> vec {{1, 3}, {-2, -2}, {5, 8}, {0, 1}}; // {{3, 3}, {5, -1}, {-2, 4}};
    int k = 2;

    priority_queue<pair<int, pair<int, int>>> heap; // max heap {dist, {x, y}}

    int f = 0;
    for (const pair<int, int>& p: vec) {
        // pay attention for constraint and data type while calculating distance
        int dist = p.first * p.first + p.second * p.second; // sqrt. will obviously be large,
                                                            // for larger value
        heap.push({dist, {p.first, p.second}});
        if (f++ >= k) heap.pop();
    }

    while (!heap.empty()) {
        cout << heap.top().second.first << ", " << heap.top().second.second << '\n';
        heap.pop();
    }

    cout << endl;

    return 0;
}
