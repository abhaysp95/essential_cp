#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Given an array of n elements, where each element is at most k away from its
// target position, devise an algorithm that sorts in O(n log k) time. For
// example, let us consider k is 2, an element at index 7 in the sorted array,
// can be at indexes 5, 6, 7, 8, 9 in the given array.

int main(void) {
    vector<int> vec = {6, 5, 3, 2, 8, 10, 9};
    int k = 3;
    priority_queue<int, vector<int>, greater<int>> heap; // min_heap

    int f = 0, s = 0;
    while (f < vec.size()) {
        heap.push(vec[f]);
        if (f >= k) {
            vec[s++] = heap.top();
            heap.pop();
        }
        f++;
    }

    while (!heap.empty()) {
        vec[s++] = heap.top();
        heap.pop();
    }

    for (const int x: vec) {
        cout << x << ", ";
    }
    cout << endl;

    return 0;
}

// Ques: why is this approach (pushing up till k and then popping/adjusting step
// by step) is better instead of putting all elements to min heap first and then
// pop out one by one ?

// Ans: Insertion of a value into at best takes O(1) time and at worst takes
// O(k) times. Here, k is the count of nodes present in the heap. So, in the
// above approach, every time there will be atmost k nodes/values present in
// heap, and once count reaches k, we are also popping from heap as we are
// pushing into it, atmost count of nodes present in heap will always be k. The
// times of pushing & popping operation done depends upon 'n' (size of arr),
// thus the above approach takes O(nlogk) time.
// When compared this with pushing all elements to heap first, the operation
// itself will take O(logn!) time which is roughly equal to O(nlogn) time.
//
// Ref:
// https://www.baeldung.com/cs/heap-insertion-complexity
// https://cs.stackexchange.com/a/162150
