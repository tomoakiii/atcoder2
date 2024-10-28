#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main () {
    long long X;
    cin >> X;
    if (X>0) {
        X--;
        X /= 10;
        X++;
    } else if (X==0) {
        X = 0;
    } else {
        X /= 10;
    }

    cout << X << endl;
    return 0;
}