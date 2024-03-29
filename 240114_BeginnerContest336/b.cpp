#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;
    int c=0;
    while (N>0){
        if (N%2 == 0) {
            c++;
            N/=2;
        } else {
            break;
        }
    }

    cout << c << endl;
    return 0;
}

