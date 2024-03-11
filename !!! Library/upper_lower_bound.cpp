#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 1, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    vector<int>::iterator iter_lower, iter_upper;
    long idx_lower, idx_upper;
    for (int key = 0; key <= 16; ++key) {
        // lower_bound
        iter_lower = lower_bound(vec.begin(), vec.end(), key);
        idx_lower = distance(vec.begin(), iter_lower);

        // upper_bound
        iter_upper = upper_bound(vec.begin(), vec.end(), key);
        idx_upper = distance(vec.begin(), iter_upper);

        // output
        cout << "----- key = " << key << " -----" << "\n";
        cout << "lower_bound: vec[" << idx_lower << "] = " << *iter_lower << "\n";
        cout << "upper_bound: vec[" << idx_upper << "] = " << *iter_upper << "\n";
        cout << "\n";
    }
    return 0;
}


// # vec = {1, 1, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15} total 13
//     idx: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
// ----- key = 8 -----
// lower_bound: vec[8] = 8
// upper_bound: vec[11] = 10