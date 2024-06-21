#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// There are given n ropes of different lengths, we need to connect these ropes
// into one rope. The cost to connect two ropes is equal to sum of their
// lengths. We need to connect the ropes with minimum cost.

int main(void) {
    vector<int> vec{3, 4, 1, 2, 5};  // {4, 3, 2, 6};
    priority_queue<int, vector<int>, greater<>> heap;  // min heap

    for (const int x: vec) heap.push(x);

    int costs = 0;
    while (heap.size() > 1) {
        int f = heap.top();
        heap.pop();
        int s = heap.top();
        heap.pop();
        heap.push(f + s);
        costs += (f + s);
    }

    cout << costs << endl;

    return 0;
}
