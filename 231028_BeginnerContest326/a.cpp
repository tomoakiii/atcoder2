#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX

int main()
{
    int X, Y;
    cin >> X >> Y;
    if (Y - X > 2 || X - Y > 3){
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}