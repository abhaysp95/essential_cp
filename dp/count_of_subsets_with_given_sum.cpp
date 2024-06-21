#include <iostream>
#include <istream>
#include <sstream>
#include <vector>

using namespace std;

vector<vector<int>> space;

int count_subsets(const vector<int>& arr, int target, int idx, int sum) {
    if (sum == target) return 1;
    if (sum > target || idx == (int)arr.size()) return 0;

    if (space[idx][sum] != -1) return space[idx][sum];

    return space[idx][sum] = count_subsets(arr, target, idx + 1, sum) + count_subsets(arr, target, idx + 1, sum + arr[idx]);
}

int count_subsets_tabulated(const vector<int>& arr, int target) {
    space.resize(arr.size() + 1, vector<int>(target + 1, 0));

    for (int i = 0; i <= (int)arr.size(); i++) {
        space[i][target] = 1;
    }

    for (int i = arr.size() - 1; i >= 0; i--) {
        for (int j = target - 1; j >= 0; j--) {
            space[i][j] = space[i + 1][j];
            if (j + arr[i] <= target) {
                space[i][j] += space[i + 1][j + arr[i]];
            }
        }
    }

    for (int i = 0; i <= arr.size(); i++) {
        for (int j = 0; j <= target; j++) {
            cout << space[i][j] << " ";
        }
        cout << '\n';
    }

    return space[0][0];
}

int main(void) {
    string input;
    getline(cin, input, '\n');
    istringstream istr(input);

    string tok;
    vector<int> arr{};
    while (getline(istr, tok, ' ')) {
        arr.push_back(stoi(tok));
    }

    int target;
    cin >> target;

    cout << "entered nums: \n";
    for (int x: arr) cout << x << " ";
    cout << '\n';
    cout << "target: " << target << '\n';


    // space.resize(arr.size() + 1, vector<int>(target + 1, -1));
    // cout << count_subsets(arr, target, 0, 0) << endl;
    cout << count_subsets_tabulated(arr, target) << endl;

    return 0;
}
