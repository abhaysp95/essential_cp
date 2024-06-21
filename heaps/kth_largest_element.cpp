#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    vector<int> num{7, 10, 4, 3, 20, 15};
    int k = 3;  // get 3rd largest element

    priority_queue<int, vector<int>, greater<int>> heap{}; // min heap (will return min element first)

    for (const int x: num) {
        heap.push(x);
        if (heap.size() > k) heap.pop();
    }

    // essentially, this is same as putting all element in min heap first and
    // getting k elements out

    cout << heap.top() << '\n';

    return 0;
}
