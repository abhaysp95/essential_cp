#include <iostream>
#include <vector>

using namespace std;

void single_duplicate() {
    vector<int> vec{3, 2, 4, 2, 1};

    for (int i = 0; i < vec.size();) {
        // https://youtu.be/uo4kuV3pWfE?list=PL_z_8CaSLPWdJfdZHiNYYM46tYQUjbBJx
        if (vec[i] != vec[vec[i] - 1]) swap(vec[i], vec[vec[i] - 1]);
        else i++;
    }

    int dup, missing;
    for (int i = 0; i < vec.size(); i++) {
        if (i + 1 != vec[i]) {
            missing = i + 1;
            dup = vec[i];
        }
    }

    /* for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << ",";
    }
    cout << '\n'; */

    cout << "missing: " << missing << ", dup: " << dup << endl;
}

void long_duplicate() {
    vector<int> vec{2, 3, 1, 8, 2, 3, 5, 1};

    // vector<pair<int, int>> ans{};  // {missing, dup}

    for (int i = 0; i < vec.size();) {
        if (vec[i] != vec[vec[i] - 1]) swap(vec[i], vec[vec[i] - 1]);
        else i++;
    }

    cout << "missing, dup\n";
    for (int i = 0; i < vec.size(); i++) {
        if (i + 1 != vec[i]) {
            cout << i + 1 << ", " << vec[i] << '\n';
        }
    }
}


int main(void) {

    long_duplicate();

    return 0;
}
