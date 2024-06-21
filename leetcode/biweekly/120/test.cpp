#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main(void) {

    std::vector<int> vec{2, 4, 6, 8};
    auto it = std::upper_bound(vec.begin(), vec.end(), 5);
    std::cout << std::distance(it, vec.begin()) << '\n';
    std::cout << *it << " - \n";
    it = std::upper_bound(vec.begin(), vec.end(), 8);
    std::cout << std::distance(it, vec.begin()) << '\n';
    std::cout << *it << " - \n";
    it = std::upper_bound(vec.begin(), vec.end(), 7);
    std::cout << std::distance(it, vec.begin()) << '\n';
    it = std::upper_bound(vec.begin(), vec.end(), 9);
    std::cout << std::distance(it, vec.begin()) << '\n';


    return 0;
}
