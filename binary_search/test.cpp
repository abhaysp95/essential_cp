#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
    vector<int> vec = {1, 3, 4, 5, 5, 5, 7, 8};
    cout << distance(vec.begin(), upper_bound(vec.begin(), vec.end(), 9)) << '\n';
    cout << distance(vec.begin(), upper_bound(vec.begin(), vec.end(), 2)) << '\n';
    cout << distance(vec.begin(), upper_bound(vec.begin(), vec.end(), 1)) << '\n';
    cout << distance(vec.begin(), upper_bound(vec.begin(), vec.end(), 5)) << '\n';
    return 0;
}
