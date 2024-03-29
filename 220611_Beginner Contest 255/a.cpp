#include <bits/stdc++.h>
using namespace std;

int main () {
    int r,c;
    cin >> r >> c;
    int A[2][2];
    cin >> A[0][0] >> A[0][1];
    cin >> A[1][0] >> A[1][1];
    cout << A[r-1][c-1] << endl;
    return 0;
}

