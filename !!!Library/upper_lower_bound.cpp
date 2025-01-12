#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 1, 3, 3, 5, 5};
    for(int i=0; i<=6; i++) {
        auto it = lower_bound(vec.begin(), vec.end(), i) - vec.begin();
        cout << it << endl;
    }
    cout << endl;
    for(int i=0; i<=6; i++) {
        auto it = upper_bound(vec.begin(), vec.end(), i) - vec.begin();
        cout << it << endl;
    }
    cout << endl;
    vector<int> vec2 = {1, 1, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    cout << (upper_bound(vec2.begin(), vec2.end(), 8) - vec2.begin()) << endl;
    return 0;
}


// # vec = {1, 1, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15} total 13
//     idx: 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
// ----- key = 8 -----
// lower_bound: vec[8] = 8
// upper_bound: vec[11] = 10